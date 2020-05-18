//╔═════════════════════════════════════════════════════════════════════════════╗
//║ Program 2:  Hi Ho Cherry-O                                                  ║
//║ Programmer: Trevor Hickey                                                   ║
//║ Class:  CSCI 230(Night),  Fall 2011                                         ║
//║ Date Submitted: March 3, 2011                                               ║
//║ Short Description:  This program simulates the childrens game               ║
//║                      of Hi Ho Cherry-O.                                     ║
//║                                                                             ║
//║ Narrative:                                                                  ║
//║ This program will simulate the game of Hi Ho Cherry-O with 4 players.       ║
//║ (Players start with zero cherries and spin a spinner to decide how many     ║
//║ cherries they lose or gain.  The first player to ten cherries first wins.   ║
//║ The user decides which players are computer players and which               ║
//║ are human players.  Computer names are randomly assigned,                   ║
//║ but human players are assigned by user input.                               ║
//║ The game displays the scoreboard at the beginning of each round.            ║
//║ The game pauses and waits for an enter key at the end of each round         ║
//║ and if it's a players turn.                                                 ║
//║                                                                             ║
//║ Special Notes:                                                              ║
//║ 	*This program contains unicode border characters.                       ║
//║                                                                             ║
//║ Continued Development:                                                      ║
//║ 	*Need to change output message of losing cherries if they do not have   ║
//║ 	 that amount to lose.  Also change the output message when a player     ║
//║ 	 recieves more cherries than they can hold.                             ║
//║     *Prevent duplicate computer names from being randomized                 ║
//╚═════════════════════════════════════════════════════════════════════════════╝

#include <iostream>
#include <cstdlib> //rand()
#include <iomanip> //setw()


using namespace std;

enum spinnerT { ONE_CHERRY, TWO_CHERRY, THREE_CHERRY, FOUR_CHERRY, BIRD, DOG, SPILL_BASKET, ERROR};

struct boardT{
	bool gameOver;
	int playersTurn;
	int spins;
	bool computerPlaying;

	boardT(){
		
		gameOver = false;
		playersTurn = 1;
		spins = 0;
	}
};
struct playerT {

	int playerNumber;
	string name;
	int cherriesInBasket;
	bool human;
	
	playerT(){
		
		cherriesInBasket = 0;
	}
};
	struct AllPlayersT {

		playerT player1,
				player2,
				player3,
				player4;

		AllPlayersT()
		{
			player1.playerNumber = 1;
			player2.playerNumber = 2;
			player3.playerNumber = 3;
			player4.playerNumber = 4;
		}
	};
	
	int MAX_CHERRIES = 10;
	int SPINNER_COUNT = 7;

//╔═════════════════════════════════════════════════════════════════════════════╗
//║               Function Prototypes                                           ║
//╚═════════════════════════════════════════════════════════════════════════════╝
void ClearScreen();

void GetPlayerInfo(AllPlayersT & allPlayers, bool & computerPlaying);
	bool BotOrHuman(int playerNumber);
	string NamePlayer(int playerNumber, bool human);
		string PlayerName(int playerNumber);
		string ComputerName();
		
void DisplayScoreboard(AllPlayersT allPlayers, bool computerPlaying, int turnNumber, int spins);
	int FindLongestName(AllPlayersT allPlayers);
	void StartMessage(int spins);
	void BuildBorder(string location, int longestName, AllPlayersT allPlayers, bool computerPlaying);
		bool CheckForComputerPlayer(AllPlayersT allPlayers);
		void FillBorderLength(int longestName, AllPlayersT allPlayers, bool computerPlaying);
	void DisplayPlayerLine(int playerNumber, string name, int cherries, bool human, int longestName);
		string DisplayPlayerOrBot(bool human);
		string SpaceBoardIfHuman(bool human);
		string DisplayCherryTreeRatio(int cherries);

spinnerT SpinSpinner(boardT & gameBoard,AllPlayersT allPlayers);
	void WaitForHuman(boardT gameBoard,AllPlayersT allPlayers);
		void SpinMessage(string name, bool human);

void PerformAction(boardT & gameBoard, spinnerT & spinner, AllPlayersT & allPlayers);
	void DecideSpinnerAction(boardT & gameBoard, spinnerT & spinner, int & cherries, string name);
		void CherrySpinMessage(int cherries, string name, int totalCherries);
			string SingularOrPluralCherries(int totalCherries);
			string GoodExclamation();
			string GreatExclamation();
			string NumberToWord(int number);
			string CherryAdjective();
			string CherryVerb();
		void AnimalSpinMessage(string animal, string name, int totalCherries);
			string BadExclamation();
			string AnimalAdjective();
			string AnimalVerb();
		void SpillBasketMessage(string name);
			string HorribleExclamation();
			string SpillBasketAdjective();
			string SpillBasketVerb();
		int CalculateNewCherryAmount(int & newAmount, int operand);

void CheckForWinner(AllPlayersT allPlayers, boardT & gameBoard);
	void PlayerWins(AllPlayersT allPlayers, int playerNumber, bool & gameOver, int spins);
		string FindWinningPlayer(AllPlayersT allPlayers, int playerNumber);
		void ShoutVictory();
	void NextPlayersTurn(int & playersTurn);

//╔═══════════════════════════════════════════════════════════════════════════╗
//║                  Main Function                                            ║
//╚═══════════════════════════════════════════════════════════════════════════╝
int main(){

	boardT gameBoard;
	spinnerT spinner;
	AllPlayersT allPlayers;

	srand(time(NULL));//seed random function
	GetPlayerInfo(allPlayers, gameBoard.computerPlaying); //gets the name of each player and whether they are human.

	while (!gameBoard.gameOver){
		DisplayScoreboard(allPlayers, gameBoard.computerPlaying, gameBoard.playersTurn, gameBoard.spins);
		spinner = SpinSpinner(gameBoard,allPlayers);
		PerformAction(gameBoard, spinner, allPlayers);
		CheckForWinner(allPlayers, gameBoard);
	}

	return 0;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This functions clears the screen of any text.                             ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void ClearScreen(){
	
	//creates 80 line breaks
	cout << string(80, '\n');
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This functions collects the name of each player and whether or not they   ║
//║ are human.                                                                ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void GetPlayerInfo(AllPlayersT & allPlayers, bool & computerPlaying){
	
	allPlayers.player1.human = BotOrHuman(allPlayers.player1.playerNumber);
	allPlayers.player1.name = NamePlayer (allPlayers.player1.playerNumber, allPlayers.player1.human);
	
	allPlayers.player2.human = BotOrHuman(allPlayers.player2.playerNumber);
	allPlayers.player2.name = NamePlayer (allPlayers.player2.playerNumber, allPlayers.player2.human);
	
	allPlayers.player3.human = BotOrHuman(allPlayers.player3.playerNumber);
	allPlayers.player3.name = NamePlayer (allPlayers.player3.playerNumber, allPlayers.player3.human);
	
	allPlayers.player4.human = BotOrHuman(allPlayers.player4.playerNumber);
	allPlayers.player4.name = NamePlayer (allPlayers.player4.playerNumber, allPlayers.player4.human);

	computerPlaying = CheckForComputerPlayer(allPlayers);
	
	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function checks to see if there are any computer players.            ║
//║ (It's used in deciding how to build the border)                           ║
//╚═══════════════════════════════════════════════════════════════════════════╝
bool CheckForComputerPlayer(AllPlayersT allPlayers){

	bool computerPlaying;
	
	if ((allPlayers.player1.human == false)  ||
		(allPlayers.player2.human == false)  ||
		(allPlayers.player3.human == false)  ||
		(allPlayers.player4.human == false)){
		computerPlaying = true;
	}
	else{

		computerPlaying = false;
	}
	
	return computerPlaying;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function determines if a player is a human or a computer.            ║
//╚═══════════════════════════════════════════════════════════════════════════╝
bool BotOrHuman(int playerNumber){

	bool human;
	string selection;

	while (selection != "y" && selection != "n"){
		cout << "Is Player " << playerNumber << " a human? (y/n) => ";
		getline(cin,selection);
	}

	if (selection == "y"){
		human = true;
	}
	else{
		human = false;
	}

	return human;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function decides on how to name a player based on whether they are a ║
//║ human or a computer.                                                      ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string NamePlayer(int playerNumber, bool human){
	
	string name;
	
	if (human == true){
		name = PlayerName(playerNumber);
	}
	else{
		name = ComputerName();
	}

	return name;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║  This function determines the name for each player.                       ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string PlayerName(int playerNumber){

	string name;
	name = "";
	
	cout << "Please enter the name for player " << playerNumber << ": ";

	while (name.length() == 0){
		getline(cin,name);
	}

	return name;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║  This function chooses a random name to assign to a computer player.      ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string ComputerName(){

	int number;

	number = (rand() % 37);

	switch (number){
		case 0: return "Ace";
		case 1: return "Alpha";
		case 2: return "Android";
		case 3: return "Bender";
		case 4: return "Blinky";
		case 5: return "Bors";
		case 6: return "Brett the Blueberry";
		case 7: return "Cassandra";
		case 8: return "Chrystal";
		case 9: return "Clunk";
		case 10: return "Gort";
		case 11: return "H.E.R.B.I.E.";
		case 12: return "Hector";
		case 13: return "K-9";
		case 14: return "Martin";
		case 15: return "Mr. Dent";
		case 16: return "Norby";
		case 17: return "Octus";
		case 18: return "Omega";
		case 19: return "Optimus Prime";
		case 20: return "Plex";
		case 21: return "Quarks";
		case 22: return "R2-D2";
		case 23: return "Robbie";
		case 24: return "Rusty";
		case 25: return "SHADOW FOX";
		case 26: return "Sonic";
		case 27: return "Specter";
		case 28: return "Spock";
		case 29: return "T-Bot";
		case 30: return "The Iron Giant";
		case 31: return "Tobor";
		case 32: return "TurtleBot";
		case 33: return "Twiki";
		case 34: return "WALL-E";
		case 35: return "Yeti";
		case 36: return "Zelda";
		}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║  This function will output the scoreboard of the game                     ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void DisplayScoreboard(AllPlayersT allPlayers, bool computerPlaying, int turnNumber, int spins){

	int longestName = FindLongestName(allPlayers);
	
	if (turnNumber == 1){ //only outputs the score board if it's the first player's turn
		                 //(this means it will either be the begginning of the game or the end of a round)
	StartMessage(spins);
	BuildBorder("top", longestName, allPlayers, computerPlaying);
	DisplayPlayerLine(allPlayers.player1.playerNumber, allPlayers.player1.name, allPlayers.player1.cherriesInBasket, allPlayers.player1.human, longestName);
	DisplayPlayerLine(allPlayers.player2.playerNumber, allPlayers.player2.name, allPlayers.player2.cherriesInBasket, allPlayers.player2.human, longestName);
	DisplayPlayerLine(allPlayers.player3.playerNumber, allPlayers.player3.name, allPlayers.player3.cherriesInBasket, allPlayers.player3.human, longestName);
	DisplayPlayerLine(allPlayers.player4.playerNumber, allPlayers.player4.name, allPlayers.player4.cherriesInBasket, allPlayers.player4.human, longestName);
	BuildBorder("bottom", longestName, allPlayers, computerPlaying);

	cout << "Press ENTER to Continue.." << endl;
	
	string throwAway;
	getline(cin,throwAway); //stops and waits for the enter key to continue

	ClearScreen();
	
	}
	
	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function will examine all of the player names and store the length   ║
//║ of the longest name.                                                      ║
//╚═══════════════════════════════════════════════════════════════════════════╝
int FindLongestName(AllPlayersT allPlayers){
	int longestName;

	longestName = allPlayers.player1.name.length();

	if (allPlayers.player2.name.length() > longestName){
		longestName = allPlayers.player2.name.length();
	}
	if (allPlayers.player3.name.length() > longestName){
		longestName = allPlayers.player3.name.length();
	}
	if (allPlayers.player4.name.length() > longestName){
		longestName = allPlayers.player4.name.length();
	}
	
	return longestName;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ Outputs a start message at the beginning of the game.                     ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void StartMessage(int spins){

	if (spins == 0){

	cout << "	╔═════════════════════╗" << endl;
	cout << "	║ LET THE GAME BEGIN! ║" << endl;
	cout << "	╚═════════════════════╝" << endl;
	
	}
	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function will build a border around the score information.           ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void BuildBorder(string location, int longestName, AllPlayersT allPlayers, bool computerPlaying){

	if (location == "top"){	
		cout << "	╔";
		FillBorderLength(longestName, allPlayers, computerPlaying);
		cout << "╗" << endl;
	}
	else if (location == "bottom"){
		cout << "	╚";
		FillBorderLength(longestName, allPlayers, computerPlaying);
		cout << "╝" << endl;
	}
	
	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function will build the top and bottom border of the scoreboard.     ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void FillBorderLength(int longestName, AllPlayersT allPlayers, bool computerPlaying){

	int borderLength;
	
	borderLength = 43 + longestName;

	for (int i = borderLength; i > 0; i--){
		cout << "═";
	}

	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║This function displays one line of the scoreboard of a particular player.  ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void DisplayPlayerLine(int playerNumber, string name, int cherries, bool human, int longestName){

	int nameLength = name.length();

	cout << "	║ Player " << playerNumber
	     << ", " << name << ", " << setw(longestName - nameLength + 1)
	     << "(" << cherries << ") "
	     << "is a " << DisplayPlayerOrBot(human) << ". "
	     << SpaceBoardIfHuman(human) << DisplayCherryTreeRatio(cherries) << " ║" << endl;

	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function will return the string "human" or "computer" depending on   ║
//║  what the player is.                                                      ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string DisplayPlayerOrBot(bool human){
	string playerKind;

	if (human == true){
		playerKind = "human";
	}
	else{
		playerKind = "computer";
	}
	
	return playerKind;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This functio nwill add the correct spacing if based on if the player is   ║
//║ a computer or a human.                                                    ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string SpaceBoardIfHuman(bool human){
	
	if (human){
		return "   ";
	}
	
	return "";
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function will output the string representation of the ratio between  ║
//║ cherries in the basket VS. cherries still on the tree.                    ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string DisplayCherryTreeRatio(int cherries){
	
	int onTree;
	string str;

	onTree = MAX_CHERRIES - cherries;

	for(;cherries != 0; cherries--){
		str+= "*";
	}
	for(;onTree != 0; onTree--){
		str+= "O";
	}

	return str;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║This function spins the spinner and recieves a random number to store as   ║
//║ an enumerated spinner value.                                              ║
//╚═══════════════════════════════════════════════════════════════════════════╝
spinnerT SpinSpinner(boardT & gameBoard, AllPlayersT allPlayers){
	
	WaitForHuman(gameBoard, allPlayers);
	gameBoard.spins+=1;
	return spinnerT(rand() % SPINNER_COUNT);
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║This function will pause the program and inform the user that it is their  ║
//║turn(provided that they are a human player.)                               ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void WaitForHuman(boardT gameBoard,AllPlayersT allPlayers){

	switch (gameBoard.playersTurn){
		case 1: SpinMessage(allPlayers.player1.name, allPlayers.player1.human);
			break;
		case 2: SpinMessage(allPlayers.player2.name, allPlayers.player2.human);
			break;
		case 3: SpinMessage(allPlayers.player3.name, allPlayers.player3.human);
			break;
		case 4: SpinMessage(allPlayers.player4.name, allPlayers.player4.human);
			break;
	}
	
	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║This function will test to see if the player is human and if so, tell them ║
//║to press enter in order to spin the spinner.                               ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void SpinMessage(string name, bool human){

	if (human){
		cout << name << ", It is your turn." << endl;
		cout << "Press ENTER to spin.." << endl;
		
		string throwAway;
		getline(cin,throwAway); //stops and waits for the enter key to continue
	}
	
	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function evaluates the players turn to decide which player should    ║
//║ have their baskets effected.                                              ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void PerformAction(boardT & gameBoard, spinnerT & spinner, AllPlayersT & allPlayers){

	switch (gameBoard.playersTurn){
		case 1:
			DecideSpinnerAction(gameBoard, spinner, allPlayers.player1.cherriesInBasket, allPlayers.player1.name);
			break;
		case 2:
			DecideSpinnerAction(gameBoard, spinner, allPlayers.player2.cherriesInBasket, allPlayers.player2.name);
			break;
		case 3:
			DecideSpinnerAction(gameBoard, spinner, allPlayers.player3.cherriesInBasket, allPlayers.player3.name);
			break;
		case 4:
			DecideSpinnerAction(gameBoard, spinner, allPlayers.player4.cherriesInBasket, allPlayers.player4.name);
			break;
	}

	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function evaluates the spinner to decide how much should be added or ║
//║ subtracted from the players total.                                        ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void DecideSpinnerAction(boardT & gameBoard, spinnerT & spinner, int & cherries, string name){


	switch (spinner)
	{
		case ONE_CHERRY:
			CalculateNewCherryAmount(cherries, 1);
			CherrySpinMessage(1, name, cherries);
			break;
		case TWO_CHERRY:
			CalculateNewCherryAmount(cherries, 2);
			CherrySpinMessage(2, name, cherries);
			break;
		case THREE_CHERRY:
			CalculateNewCherryAmount(cherries, 3);
			CherrySpinMessage(3, name, cherries);
			break;
		case FOUR_CHERRY:
			CalculateNewCherryAmount(cherries, 4);
			CherrySpinMessage(4, name, cherries);
			break;
		case BIRD:
			CalculateNewCherryAmount(cherries, -2);
			AnimalSpinMessage("bird", name, cherries);
			break;
		case DOG:
			CalculateNewCherryAmount(cherries, -2);
			AnimalSpinMessage("dog", name, cherries);
			break;
		case SPILL_BASKET:
			CalculateNewCherryAmount(cherries, -cherries);
			SpillBasketMessage(name);
	}

	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function adds the amount decided from the spinner to the players     ║
//║ total. This function makes sure the new amount is ≥ 0 and ≤ 10.           ║
//╚═══════════════════════════════════════════════════════════════════════════╝
int CalculateNewCherryAmount(int & newAmount, int operand){
	
	newAmount = newAmount + operand;
	
	if (newAmount < 0){
		newAmount = 0;
	}

	if (newAmount > 10){
		newAmount = 0;
	}
	
	return newAmount;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function outputs an explanation of what is happening in the game     ║
//║ from the user's spin!                                                     ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void CherrySpinMessage(int cherries, string name, int totalCherries){

	switch (cherries){
		case 1:
		case 2: cout << GoodExclamation() << endl;
			break;
		case 3:
		case 4: cout << GreatExclamation() << endl;
			break;
	}

	cout << "THE SPINNER LANDS ON " << NumberToWord(cherries) << "!" << endl;
	
	cout << name << " just " << CherryAdjective() << CherryVerb() << " "
	     << cherries << " cherr" << SingularOrPluralCherries(cherries) << " from the tree!" << endl;

	cout << name <<"'s basket now contains " << totalCherries << " cherr"
	     << SingularOrPluralCherries(totalCherries) << "." << endl << endl;

	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function converts a number into a word.                              ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string NumberToWord(int number){

	switch (number){
		case 1: return "ONE";
		case 2: return "TWO";
		case 3: return "THREE";
		case 4: return "FOUR";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function evaluates if the output of the word cherry should be        ║
//║ "cherry" (singular), or "cherries (plural).                               ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string SingularOrPluralCherries(int totalCherries){
	string word;
	if (totalCherries == 1){
		word = "y";
	}
	else{
		word = "ies";
	}

	return word;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function randomonly decides a good exclamation to shout.             ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string GoodExclamation(){

	int number;
	
	number = (rand() % 9);
	
	switch (number){
		case 0: return "Cool!";
		case 1: return "Cool beans!";
		case 2: return "Good!";
		case 3: return "How fortunate!";
		case 4: return "Lucky!";
		case 5: return "Nice!";
		case 6: return "Sweet!";
		case 7: return "Wizard!";
		case 8: return "Yay!";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function randomonly decides a great exclamation to shout.            ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string GreatExclamation(){

	int number;
	
	number = (rand() % 7);

	switch (number){
		case 0: return "Awesome!";
		case 1: return "BOOYAH!";
		case 2: return "Blizzard!";
		case 3: return "Great!";
		case 4: return "Success!";
		case 5: return "WOOOOO!";
		case 6: return "Yes! (with a fist pump)";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function randomonly decides what the adjective is for a player       ║
//║ getting a cherry.                                                         ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string CherryAdjective(){

	int number;
	
	number = (rand() % 28); // 50/50 chance of getting an adjective or not

	switch (number){
		case 0: return "admirably ";
		case 1: return "beautifully ";
		case 2: return "cheerfully ";
		case 3: return "excellently ";
		case 4: return "graciously ";
		case 5: return "happily ";
		case 6: return "joyfully ";
		case 7: return "laughingly ";
		case 8: return "merrily ";
		case 9: return "pleasurably ";
		case 10: return "satisfyingly ";
		case 11: return "successfully ";
		case 12: return "triumphantly ";
		case 13: return "victoriously ";
		default: return "";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function randomonly decides a verb for recieving a cherry.           ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string CherryVerb(){

	int number;
	
	number = (rand() % 32);

	switch (number){
		case 0: return "aquired";
		case 1: return "attained";
		case 2: return "catched";
		case 3: return "caught";
		case 4: return "collected";
		case 5: return "earned";
		case 6: return "gained";
		case 7: return "gathered";
		case 8: return "got";
		case 9: return "grabed";
		case 10: return "grappled";
		case 11: return "hooked";
		case 12: return "lassoed";
		case 13: return "looted";
		case 14: return "nabbed";
		case 15: return "obtained";
		case 16: return "picked";
		case 17: return "reached";
		case 18: return "received";
		case 19: return "ripped off";
		case 20: return "secured";
		case 21: return "seized";
		case 22: return "shot down";
		case 23: return "snagged";
		case 24: return "snapped off";
		case 25: return "snatched";
		case 26: return "stripped";
		case 27: return "stole";
		case 28: return "threw a shoe and knocked down";
		case 29: return "took";
		case 30: return "took hold of";
		case 31: return "won";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function outputs a message for when the spinner lands on an animal.  ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void AnimalSpinMessage(string animal, string name, int totalCherries){
	
	cout << BadExclamation() << endl;

	cout << "THE SPINNER LANDS ON ";
	     if (animal == "dog"){cout << "DOG";}
	     else{cout << "BIRD";}
	     cout << endl;
		 
	cout << "Looks like a " << animal << " " << AnimalAdjective() << AnimalVerb()
	     << " 2 of " << name << "'s cherries and put them back in the tree!" << endl;
		 
	cout << name << "'s basket now contains " << totalCherries << " cherr"
	     << SingularOrPluralCherries(totalCherries) << "." << endl << endl;

	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function randomonly decides a bad exclamation to shout.              ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string BadExclamation(){
	
	int number;
	
	number = (rand() % 11);
	
	switch (number){
		case 0: return "Aww shucks!";
		case 1: return "Awwww";
		case 2: return "Bad!";
		case 3: return "Blast!";
		case 4: return "Darn!";
		case 5: return "Drats!";
		case 6: return "Fiddlesticks!";
		case 7: return "How unfortunate!";
		case 8: return "Oh no!";
		case 9: return "Shoot!";
		case 10: return "Uh Oh!";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function randomonly decides what the adjective is for the animal     ║
//║ stealing a cherry.                                                        ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string AnimalAdjective(){

	int number;
	
	number = (rand() % 58);
	
	switch (number){
		case 0: return "atrociously ";
		case 1: return "barbarically ";
		case 2: return "brutally ";
		case 3: return "brutishly ";
		case 4: return "callously ";
		case 5: return "cruelly ";
		case 6: return "demoniacally ";
		case 7: return "diabolically ";
		case 8: return "ferociously ";
		case 9: return "fiercely ";
		case 10: return "heartlessly ";
		case 11: return "immorally ";
		case 12: return "malevolently ";
		case 13: return "maliciously ";
		case 14: return "meanly ";
		case 15: return "mercilessly ";
		case 16: return "murderously ";
		case 17: return "pitilessly ";
		case 18: return "remorselessly ";
		case 19: return "ruthlessly ";
		case 20: return "savagely ";
		case 21: return "spitefully ";
		case 22: return "unkindly ";
		case 23: return "unrelentingly ";
		case 24: return "viciously ";
		case 25: return "violently ";
		case 26: return "wickedly ";
		case 27: return "wildly ";
		case 28: return "wrongly ";
		default: return "";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function randomonly decides a verb for stealing a cherry.            ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string AnimalVerb(){
	
	int number;
	
	number = (rand() % 6);

	switch (number){
		case 0: return "abducted";
		case 1: return "engulfed";
		case 2: return "grabbed";
		case 3: return "seized";
		case 4: return "snatched";
		case 5: return "stole";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function will output a message when th eplayer spills their basket.  ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void SpillBasketMessage(string name){

	cout << HorribleExclamation() << endl;
	cout << "THE SPINNER LANDS ON SPILL!" << endl;
	cout << "Looks like " << name <<" " << SpillBasketAdjective() << SpillBasketVerb() <<" the basket!" << endl;
	cout << name << "'s basket is now empty!" << endl << endl;

	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function randomonly decides a horrible exclamation to shout.         ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string HorribleExclamation(){

	int number;
	
	number = (rand() % 9);

	switch (number){
		case 0: return "0.0";
		case 1: return ":O ...";
		case 2: return "ARE YOU KIDDING!!";
		case 3: return "GASP!";
		case 4: return "MWAHAHA!";
		case 5: return "NOOOOO!";
		case 6: return "THIS IS BANANAS!!";
		case 7: return "WHY!?!?!";
		case 8: return "WTF!!!!";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function randomly chooses and adjective for spilling the basket.     ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string SpillBasketAdjective(){

	int number;
	
	number = (rand() % 28);

	switch (number){
		case 0: return "awkwardly ";
		case 1: return "carelessly ";
		case 2: return "clumsily ";
		case 3: return "crazily ";
		case 4: return "disgracefully ";
		case 5: return "foolishly ";
		case 6: return "mistakenly ";
		case 7: return "recklessly ";
		case 8: return "senselessly ";
		case 9: return "stumblingly ";
		case 10: return "stupidly ";
		case 11: return "stupidly ";
		case 12: return "unpleasantly ";
		case 13: return "unwisely ";
		default: return "";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function decides on a verb for a player spilling the basket.         ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string SpillBasketVerb(){
	
	int number;
	
	number = (rand() % 6);
	
	switch (number){
		case 0: return "dropped";
		case 1: return "kicked";
		case 2: return "knocked over";
		case 3: return "poured";
		case 4: return "spilled";
		case 5: return "tripped over";
	}
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function checks to see if any player has reached the winning amount  ║
//║ of cherries and decides to advance to the next turn or handle the player  ║
//║ winning.                                                                  ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void CheckForWinner(AllPlayersT allPlayers, boardT & gameBoard){

	if ((allPlayers.player1.cherriesInBasket >= 10) ||
		(allPlayers.player2.cherriesInBasket >= 10) ||
		(allPlayers.player3.cherriesInBasket >= 10) ||
		(allPlayers.player4.cherriesInBasket >= 10)){
			PlayerWins(allPlayers, gameBoard.playersTurn, gameBoard.gameOver, gameBoard.spins);
	}
	else{

		NextPlayersTurn(gameBoard.playersTurn);
	}


	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function announces the winner of the game and changes a flag to drop ║
//║ out of the loop and exit the program.                                     ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void PlayerWins(AllPlayersT allPlayers, int playerNumber, bool & gameOver, int spins){

	gameOver = true;
	
	ShoutVictory();
	cout << "The Winner is: " << FindWinningPlayer(allPlayers, playerNumber) << "!" << endl;
	cout << "The Game Finnished in " << spins/4 << " Turns!" << endl;

	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function returns the name of the winner by looking at whose turn it  ║
//║ is.                                                                       ║
//╚═══════════════════════════════════════════════════════════════════════════╝
string FindWinningPlayer(AllPlayersT allPlayers, int playerNumber){
	string playerName;

	switch (playerNumber){
		case 1:
			playerName = allPlayers.player1.name;
			break;
		case 2:
			playerName = allPlayers.player2.name;
			break;
		case 3:
			playerName = allPlayers.player3.name;
			break;
		case 4:
			playerName = allPlayers.player4.name;
	}
	
	return playerName;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║ This function advances the player turn by looking at what turn the game   ║
//║ is currently on.                                                          ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void NextPlayersTurn(int & playersTurn){
	
	if (playersTurn <= 3){
		playersTurn++;
	}
	else{
		playersTurn = 1;
	}

	return;
}
//╔═══════════════════════════════════════════════════════════════════════════╗
//║  This function outputs the phrase "Hi Ho Cherry-O!"                       ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void ShoutVictory(){
	
	cout << "              _    _ _   _    _"                         << endl;
	cout << "             | |  | (_) | |  | |"                        << endl;
	cout << "             | |__| |_  | |__| | ___"                    << endl;
	cout << "             |  __  | | |  __  |/ _ \\"                  << endl;
	cout << "             | |  | | | | |  | | (_) |"                  << endl;
	cout << "             |_|  |_|_| |_|  |_|\\___/"                  << endl;
	cout << "  _____ _                                  ____  _"      << endl;
	cout << " / ____| |                                / __ \\| |"    << endl;
	cout << "| |    | |__   ___ _ __ _ __ _   _ ______| |  | | |"     << endl;
	cout << "| |    | '_ \\ / _ \\ '__| '__| | | |______| |  | | |"   << endl;
	cout << "| |____| | | |  __/ |  | |  | |_| |      | |__| |_|"     << endl;
	cout << " \\_____|_| |_|\\___|_|  |_|   \\__, |       \\____/(_)" << endl;
	cout << "                              __/ |"                     << endl;
	cout << "                             |___/"                      << endl;

	return;
}



	





	
