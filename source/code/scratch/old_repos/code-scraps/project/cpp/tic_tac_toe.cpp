/*
  +------------------------------------------------------------------------+
  | This program builds the entire search space for noughts and crosses.   |
  |                                                                        |
  | Each state consists of a board and the result. The result is simply    |
  | whether X or O wins or whether there is a draw or, if the game is not  |
  | completed, which turn it is.                                           |
  |                                                                        |
  |   The board is a 3-by-3 array. Each position on the board contains two |
  | pieces of information: move and child. The move is X, O, or none. A    |
  | child is the pointer to the next state from the current one.           |
  |                                                                        |
  | Generally, each position on a board will contain either (1) a move of  |
  | X or O and a null child or (2) a none move and the pointer to the      |
  | child for the new move to be placed in the position. The exception is  |
  | when a win occurs and not all positions have been played. In this      |
  | case, a none move will also have a null child.                         |
  |------------------------------------------------------------------------+
  | Trevor Hickey                                                          |
  | CSCI 370 (ARTIFICIAL INTELLIGENCE)                                     |
  | October 2, 2012                                                        |
  | Dr. Meyer                                                              |
  +------------------------------------------------------------------------+
*/

//STD libraries
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sstream>

//the game board is a square, the dimensions are set here
const unsigned int BoardSzConst = 3;
const unsigned int SquareCntConst = BoardSzConst * BoardSzConst;

enum MoveT {X, O, NONE};
enum StandT {X_TURN, O_TURN, DRAW, X_WIN, O_WIN};

struct StateStruct;
struct PlaceStruct {
   MoveT move;
   StateStruct* next;
};
typedef PlaceStruct BoardType[BoardSzConst][BoardSzConst];

struct StateStruct {
   BoardType board;
   StandT result;
};
const unsigned int INDENT_AMOUNT = 4;
struct StatsT {

	//statistical information describing the game tree
	unsigned int wins;
	unsigned int losses;
	unsigned int ties;
	unsigned int nodes;

	//initialize values to zero
	StatsT(void)
	: wins(0)
	, losses(0)
	, ties(0)
	, nodes(0)
	{}
};
void BuildSearch(StateStruct&);
void BuildChild(int, int, StateStruct&);
bool CheckWin(BoardType, MoveT);
void CopyBoard(BoardType, BoardType&);
void SetUp(StateStruct&);
void Show_Stats(StateStruct& start);
void Analysis_SubTree(StateStruct&, StatsT&);
void Update_Game_Conclusion(StateStruct& state, StatsT& data);
void Print_Tree(StateStruct& start);
char Get_Print_Choice(void);
void Print_Row(StateStruct& state, int depth);
void Print_Subtree(StateStruct& state, unsigned int& begin, unsigned int& end, unsigned int depth=0);
std::string Add_Commas(unsigned int number);
int main(){

   //build the tree!
   StateStruct start;
   SetUp(start);
   BuildSearch(start);

   //We grab some stats about the tree,
   //show them to the user, and then allow
   //them to print portions of the tree
   Show_Stats(start); //<- get and show stats
   Print_Tree(start); //<- let user print tree portions

   return EXIT_SUCCESS;
}
void Show_Stats(StateStruct& start) {
	using std::cout;

	static StatsT data;
	Analysis_SubTree(start, data);

	cout << "\n Game Tree Statistics\n";
	cout << "X Wins:   \t" << Add_Commas(data.wins) << '\n';
	cout << "X Losses: \t" << Add_Commas(data.losses) << '\n';
	cout << "Ties:     \t" << Add_Commas(data.ties) << '\n';
	cout << "Nodes:    \t" << Add_Commas(data.nodes) << "\n\n";
}
void Analysis_SubTree(StateStruct& state, StatsT& data) {

	for (int i=0; i<SquareCntConst; ++i) {

		//recursively analyze the children
		if (state.board[i/BoardSzConst][i%BoardSzConst].next != NULL) {
			Analysis_SubTree(*state.board[i/BoardSzConst][i%BoardSzConst].next, data);
		}
	}

	//update stats!
	Update_Game_Conclusion(state,data);
	++data.nodes;

	return;
}
void Update_Game_Conclusion(StateStruct& state, StatsT& data){

	//increment the result of the child node
	//(How did the particular game end)
	switch (state.result) {
		case X_WIN:
			++data.wins;
			break;

		case O_WIN:
			++data.losses;
			break;

		case DRAW:
			++data.ties
			;break;

		default:;
			//if we hit here,
			//it's not a child node- which means,
			//we have not arrived at a game conclusion yet
	}

	return;
}
void Print_Tree(StateStruct& start) {
	using std::cout;
	using std::cin;

	unsigned int start_node, end_node;
	char print_choice;

	//continue printing portions of the tree until the user asks to exit
	do {
		print_choice = Get_Print_Choice();

		if (print_choice == 'y') {

			cout << "Please type how far down the tree would you like to start: "; cin >> start_node;
			cout << "Please type how far down the tree would you like to end: ";   cin >> end_node;

			Print_Subtree(start,start_node,end_node);
		}

	} while (print_choice == 'y');

	return;
}
char Get_Print_Choice(void){

	char print_choice;

	std::cout << "Print a subportion of the tree? (y/n) => ";
	std::cin >> print_choice;
	print_choice = tolower(print_choice);

	while (print_choice != 'n' && print_choice != 'y'){
		std::cout << "Bad Input.\n Print a subportion of the tree? (y/n) => ";
		std::cin >> print_choice;
		print_choice = tolower(print_choice);
	}

	return print_choice;
}
void Print_Subtree(StateStruct& state, unsigned int& start_node, unsigned int& end_node, unsigned int depth) {
	static int max = end_node;
	for (int i=0; i<SquareCntConst; ++i) {

		//print current node and adjust the print range
		if (i == 0) {
			if (start_node == 0){
				std::cout << (max-end_node) << "|";
				Print_Row(state, depth);
			}
			else{
				--start_node;
			}

			--end_node;
		}

		//print children unless the user restricted it
		if (end_node != -1){
			if (NULL != state.board[i/BoardSzConst][i%BoardSzConst].next) {
				Print_Subtree(*state.board[i/BoardSzConst][i%BoardSzConst].next, start_node, end_node, depth+1);
			}
		}
	}
	return;
}
void Print_Row(StateStruct& state, int depth) {
	using std::cout;

	cout << depth;

	//print indent
	for (int i=0; i<depth*INDENT_AMOUNT; ++i) {cout << " ";}

	for (int i=0; i<SquareCntConst; ++i){

		//print column start
		if (i%BoardSzConst == BoardSzConst-3){ cout << '[';};

		//print row state
		switch (state.board[i/BoardSzConst][i%BoardSzConst].move) {
			case X: 	cout << 'X'; 	break;
			case O: 	cout << 'O'; 	break;
			case NONE: 	cout << '_'; 	break;
		}

		//print column end
		if (i%BoardSzConst == BoardSzConst-1){ cout << ']';};
	}
	cout << '\n';
}
std::string Add_Commas(unsigned int number){
	using namespace std;

	//add commas to the output of a number
	stringstream ss;
	ss << number;
	string str_number = ss.str();
	int counter = 0;
	for (int i = str_number.length()-1; i >= 0; --i){
		++counter;
		if (3 == counter){

			if (i != 0){
			str_number.insert(i,",");
			}

			counter = 0;
		}
	}

	return str_number;
}
void SetUp(StateStruct& state){
   for (int r = 0; r < BoardSzConst; r++)
      for (int c = 0; c < BoardSzConst; c++) {
         state.board[r][c].move = NONE;
         state.board[r][c].next = NULL;
   }
   state.result = X_TURN;
   return;
}
void BuildSearch(StateStruct& state){
   bool goon = false;
   for (int r = 0; r < BoardSzConst; r++)
      for (int c = 0; c < BoardSzConst; c++)
         if (state.board[r][c].move == NONE) {
            BuildChild(r, c, state);
            goon = true;
         }
   if (!goon)
      state.result = DRAW;
   return;
}
void BuildChild(int r, int c, StateStruct& state){
   StateStruct* child = new StateStruct;
   state.board[r][c].next = child;
   CopyBoard(state.board, child->board);
   MoveT player = state.result == X_TURN ? X : O;
   child->board[r][c].move = player;
   if (CheckWin(child->board, player)) {
      StandT winner = player == X ? X_WIN : O_WIN;
      child->result = winner;
   }
   else {
      StandT turn = state.result == X_TURN ? O_TURN : X_TURN;
      child->result = turn;
      BuildSearch(*child);
   }
   return;
}
void CopyBoard(BoardType fromBoard, BoardType& toBoard){
   for (int r = 0; r < BoardSzConst; r++)
      for (int c = 0; c < BoardSzConst; c++) {
         toBoard[r][c].move = fromBoard[r][c].move;
         toBoard[r][c].next = NULL;
   }
   return;
}
bool CheckWin(BoardType board, MoveT player){
   for (int r = 0; r < BoardSzConst; r++) {
      bool rowWin = true;
      for (int c = 0; c < BoardSzConst; c++)
         rowWin = rowWin && (board[r][c].move == player);
      if (rowWin) return true;
   }
   for (int c = 0; c < BoardSzConst; c++) {
      bool colWin = true;
      for (int r = 0; r < BoardSzConst; r++)
         colWin = colWin && (board[r][c].move == player);
      if (colWin) return true;
   }
   bool diagWin = true;
   for (int r = 0; r < BoardSzConst; r++)
      diagWin = diagWin && (board[r][r].move == player);
   if (diagWin) return true;
   bool revDiagWin = true;
   for (int r = 0; r < BoardSzConst; r++)
      revDiagWin = revDiagWin && (board[r][BoardSzConst-r-1].move == player);
   if (revDiagWin) return true;
   return false;
}
