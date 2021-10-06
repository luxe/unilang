//Trevor Hickey
//Dan Bennett
//March 30, 2011
//Program 3 (Candyland)

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "board.h"
#include "deck.h"
#include "contestants.h"

const int MAX_SPACES = 200;

	//taken from input file
	struct fileDataT{
		int numberOfSpaces;
		int numberOfCharacters;
		int numberOfPenalties;
		int numberOfShortcuts;
		int numberOfPlayers;
		char gameMode; //(V)erbose (S)ilent
		int  numberOfTrials;
	};

	struct statisticsT{
		int gamesPlayed;
		int longestGame;
		int shortestGame;
		int averageTurns;
		
		statisticsT(){
			gamesPlayed = 0;
			longestGame = 0;
			shortestGame = 0;
			averageTurns = 0;
		}
	};
	
//╔═══════════════════════════════════════════════════════════════════════════╗
//║  Function Prototypes                                                      ║
//╚═══════════════════════════════════════════════════════════════════════════╝
void SetupGame(ifstream & setupFile, fileDataT & fileData, BoardT & board, DeckT & deck, ContestantsT & contestants);
	void OpenSetupFile(ifstream & setupFile, string setupFileName);
		string GetSetupFileName();
	void ReadThroughSetupFile(ifstream & setupFile, fileDataT & fileData, BoardT & board, DeckT & deck, ContestantsT & contestants);
		void BuildCharacters(ifstream & setupFile, int numberOfCharacters, BoardT & board, DeckT & deck);
		void BuildPenalties(ifstream & setupFile, int numberOfPenalties, BoardT & board, DeckT & deck);
		void BuildShortcuts(ifstream & setupFile, int numberOfShortcuts, BoardT & board, DeckT & deck);
		void BuildPlayers(ifstream & setupFile, int numberOfPlayers, ContestantsT & contestants);
	void FillBoard(BoardT & board);
	void FillDeck(DeckT & deck);
	void ShuffleDeck(DeckT & deck);
	void SortPlayers(ContestantsT & contestants);
void OutputMode(char gameMode);
CardT DrawCard(DeckT & deck, ContestantsT contestants);
void MovePlayer(CardT currentCard, ContestantsT & contestants, BoardT board);
	void MovePlayerToCharacter(CardT currentCard, ContestantsT & contestants);
	void MovePlayerToColor(CardT currentCard, ContestantsT & contestants, BoardT board);
		void CheckForSpecialCel(ContestantsT & contestants, int position, bool & turnOver, BoardT board);
			void MoveToShortcut(ContestantsT & contestants, int newPosition);
void CheckForWinner(ContestantsT contestants, bool & winner);
void ChangeTurns(ContestantsT & contestants);
void OutputResults(ContestantsT contestants);

//╔═══════════════════════════════════════════════════════════════════════════╗
//║  Main Function                                                            ║
//╚═══════════════════════════════════════════════════════════════════════════╝
int main(){
	
	ifstream setupFile;
	fileDataT fileData; //information on how the game should be setup (populated by file data)
	statisticsT statistics;
	bool winner = false;
	int roundCounter = 1;
	

	srand(time(NULL)); //seed random function


	BoardT board;               //create an empty board
	DeckT deck;                //create an empty deck
	ContestantsT contestants; //create a collection of empty contestant spaces
 	CardT currentCard;       //create an empty drawn card
	
	SetupGame(setupFile, fileData ,board, deck, contestants);
	
	OutputMode(fileData.gameMode);
	for (int i = 1; i <= fileData.numberOfTrials; i++){

		while (winner == false){
			cout << "Round: " << roundCounter << endl;
			roundCounter++;
			for(int i = 1; i <= fileData.numberOfPlayers; i++){
				currentCard = DrawCard(deck, contestants);
				MovePlayer(currentCard, contestants, board);
				CheckForWinner(contestants, winner);
				if (winner == false){
					ChangeTurns(contestants);
				}
			}

		}
		OutputResults(contestants);
	}
	
	setupFile.close();

	return 0;
}




void SetupGame(ifstream & setupFile, fileDataT & fileData, BoardT & board, DeckT & deck, ContestantsT & contestants){

	string setupFileName;
	OpenSetupFile (setupFile, setupFileName);
	ReadThroughSetupFile(setupFile, fileData,board, deck, contestants);
	FillBoard(board);
	FillDeck(deck);
	ShuffleDeck(deck);
	SortPlayers(contestants);
	
	return;
}
void OpenSetupFile (ifstream & setupFile, string setupFileName){
	
	setupFileName = GetSetupFileName();
	
	//opens a file which contains a list of game setup information
	//*files must be in the program's directory
	setupFile.open(setupFileName.c_str());

	//tests to make sure the file was opened(continue askinf for a file until it is opened properly)
	while(!setupFile) {
		cout << endl << "ERROR: Failed to open " << "'"<< setupFileName <<"'." << endl
		     << "*please make sure you have the file '" << setupFileName <<"' "
			 << "is in the same directory as this program." <<endl << endl;

		setupFileName = GetSetupFileName();
		setupFile.open(setupFileName.c_str());
		
        }
        
	return;
}
string GetSetupFileName(){

	string filename;

	cout << "Please enter the name of the setup file you run like to run candyland with: ";
	cin >> filename;

	return filename;
}
void ReadThroughSetupFile(ifstream & setupFile, fileDataT & fileData, BoardT & board, DeckT & deck, ContestantsT & contestants){

	setupFile >> fileData.numberOfSpaces;
	
	setupFile >> fileData.numberOfCharacters;
	BuildCharacters(setupFile, fileData.numberOfCharacters, board, deck);

	setupFile >> fileData.numberOfPenalties;
	BuildPenalties(setupFile, fileData.numberOfPenalties, board, deck);

	setupFile >> fileData.numberOfShortcuts;
	BuildShortcuts(setupFile, fileData.numberOfShortcuts, board, deck);

	setupFile >> fileData.numberOfPlayers;
	BuildPlayers(setupFile, fileData.numberOfPlayers, contestants);

	setupFile >> fileData.gameMode;
	setupFile >> fileData.numberOfTrials;
	
	return;
}
void BuildCharacters(ifstream & setupFile, int numberOfCharacters, BoardT & board, DeckT & deck){
	
	int characterPosition;
	string characterName;
		
	for (int i = 0; i < numberOfCharacters; i++){
		setupFile >> characterPosition;
		getline(setupFile, characterName);
		
		//create character cards and place them in the deck
		deck.CreateCard(i, characterName, characterPosition);

		//create character spaces and place them on board
		board.CreateBoardSpace(characterPosition, CHARACTER, characterName);
		
	}
	return;

}
void BuildPenalties(ifstream & setupFile, int numberOfPenalties, BoardT & board, DeckT & deck){

	int penaltyPosition;
	string penaltyName;

	for (int i = 0; i < numberOfPenalties; i++){
		setupFile >> penaltyPosition;
		getline(setupFile, penaltyName);

		//create penalty spaces and place them on board
		board.CreateBoardSpace(penaltyPosition, PENALTY, penaltyName);
	}
}
void BuildShortcuts(ifstream & setupFile, int numberOfShortcuts, BoardT & board, DeckT & deck){

	int shortcutStartPosition;
	int shortcutEndPosition;
	string shortcutName;

	for (int i = 0; i < numberOfShortcuts; i++){
		setupFile >> shortcutStartPosition;
		setupFile >> shortcutEndPosition;
		getline(setupFile, shortcutName);

		//create shortcut spaces and place them on board
		board.CreateBoardSpace(shortcutStartPosition, shortcutEndPosition, shortcutName);

	}
}
void BuildPlayers(ifstream & setupFile, int numberOfPlayers, ContestantsT & contestants){

	int characterAge;
	string characterName;

	for (int i = 0; i < numberOfPlayers; i++){
		setupFile >> characterAge;
		getline(setupFile, characterName);
		characterName.erase (0,1); //remove space at the beginning of every name

		//create a player and place them in contestants
		contestants.CreatePlayer(i, characterAge, characterName);
	}
}
void FillBoard(BoardT & board){
	board.FillInColors();
	return;
}
void FillDeck(DeckT & deck){
	deck.FillInCards();
	return;
}
void ShuffleDeck(DeckT & deck){
	deck.Shuffle();
	return;
}
void SortPlayers(ContestantsT & contestants){
	contestants.Sort();
	return;
}
CardT DrawCard(DeckT & deck, ContestantsT contestants){

	CardT card;
	
	card = deck.DrawACard();
	cout << contestants.GetName() << " draws a " << card.ConvertColorToString(card.GetColor()) << " card." << endl;

	return card;
}
void OutputMode(char gameMode){
	if (gameMode == 'V'){
		cout << "Verbose Mode:" << endl;
	}
	else{
		cout << "Silent Mode:" << endl;
	}

	return;
}
void MovePlayer(CardT currentCard, ContestantsT & contestants, BoardT board){
	bool turnOver = false;
	
	if (currentCard.GetColor() == PINK){
		MovePlayerToCharacter(currentCard, contestants);
	}
	else{
		MovePlayerToColor(currentCard, contestants, board);
	}

	while (turnOver != false){
		CheckForSpecialCel(contestants,contestants.GetPosition(), turnOver, board);
	}
	cout << "Turn over" << endl;

	return;
}



void MovePlayerToCharacter(CardT currentCard, ContestantsT & contestants){
	

	int charPosition;
	int playerPosition;

	charPosition = currentCard.GetPosition();
	playerPosition = contestants.GetPosition();

		contestants.MovePlayer(charPosition);
		cout << contestants.GetName() << " moves from space " << playerPosition << " to space " << charPosition << "." << endl;

	return;
}
void CheckForSpecialCel(ContestantsT & contestants, int position, bool & turnOver, BoardT board){
	
	BoardSpaceT currentBoard;
 	currentBoard = board.GetBoardSpace(position);

	if (currentBoard.GetSpaceAttribute() == SHORTCUT){
		MoveToShortcut(contestants, currentBoard.GetEndPosition());
	}
	else{
		turnOver = true;
	}
}
void MoveToShortcut(ContestantsT & contestants, int newPosition){
	int playerPosition = contestants.GetPosition();
	contestants.MovePlayer(newPosition);
	cout << contestants.GetName() << " moves from space " << playerPosition << " to space " << playerPosition << "." << endl;

	return;
}
void MovePlayerToColor(CardT currentCard, ContestantsT & contestants, BoardT board){

	int playerPosition;
	ColorT moveColor;
	ColorT searchColor;
	int colorCount;
	int newPosition;
	

	playerPosition = contestants.GetPosition();
	moveColor = currentCard.GetColor();
	colorCount = currentCard.GetColorCount();

	newPosition = playerPosition;
	
	
	for (int i = 1; moveColor != searchColor; i++){
		searchColor = board.GetColor(playerPosition+i);
		contestants.MovePlayer(playerPosition+i);
		newPosition++;
	}
	
	cout << contestants.GetName() << " moves from space " << playerPosition << " to space " << newPosition << "." << endl;

	return;
}

void CheckForWinner(ContestantsT contestants, bool & winner){
	if (contestants.GetPosition() > MAX_SPACES){
		winner = true;
	}

	return;
}

void ChangeTurns(ContestantsT & contestants){
	contestants.ChangePlayer();
	return;
}
void OutputResults(ContestantsT contestants){
	cout << "The winner is " << contestants.GetName() << "." << endl;
	return;
}






