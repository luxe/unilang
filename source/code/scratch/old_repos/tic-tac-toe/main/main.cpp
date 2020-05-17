#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
using namespace std;
enum class STATE:char{X, O, NONE};
std::string print(STATE const& s, int const& n) {if (s == STATE::X) return "X";if (s == STATE::O) return "O";return std::to_string(n);};
class Board {public: Board() {board.fill(STATE::NONE);}public: void display() {
std::cout << "+---+---+---+\n";std::cout << "| " <<  print(board[0],0) <<  " | " <<  print(board[1],1) <<  " | " <<  print(board[2],2) <<  " |\n";
std::cout << "+---+---+---+\n";std::cout << "| " <<  print(board[3],3) <<  " | " <<  print(board[4],4) <<  " | " <<  print(board[5],5) <<  " |\n";
std::cout << "+---+---+---+\n";std::cout << "| " <<  print(board[6],6) <<  " | " <<  print(board[7],7) <<  " | " <<  print(board[8],8) <<  " |\n";
std::cout << "+---+---+---+\n";return;};public: bool set(int num, bool x_turn) {if (board[num] == STATE::NONE) x_turn ? board[num]=STATE::X : board[num]=STATE::O;else return false;return true;}
public:std::array<STATE, 9> board;};
void print_turn(bool x_turn) {x_turn ? cout<< "x turn" : cout<< "y turn"; cout << '\n';}
bool check_winner(Board const& board) {if (board.board[0] == STATE::X && board.board[1] == STATE::X && board.board[2] == STATE::X) {std::cout << "x wins\n"; return true;}
 if (board.board[3] == STATE::X && board.board[4] == STATE::X && board.board[5] == STATE::X) {std::cout << "x wins\n"; return true;}
if (board.board[6] == STATE::X && board.board[7] == STATE::X && board.board[8] == STATE::X) {std::cout << "x wins\n"; return true;}
if (board.board[0] == STATE::X && board.board[3] == STATE::X && board.board[6] == STATE::X) {std::cout << "x wins\n"; return true;}
 if (board.board[1] == STATE::X && board.board[4] == STATE::X && board.board[7] == STATE::X) {std::cout << "x wins\n"; return true;}
if (board.board[2] == STATE::X && board.board[5] == STATE::X && board.board[8] == STATE::X) {std::cout << "x wins\n"; return true;}
 if (board.board[0] == STATE::X && board.board[4] == STATE::X && board.board[8] == STATE::X) {std::cout << "x wins\n"; return true;}
if (board.board[6] == STATE::X && board.board[4] == STATE::X && board.board[2] == STATE::X) {std::cout << "x wins\n"; return true;}
 if (board.board[0] == STATE::O && board.board[1] == STATE::O && board.board[2] == STATE::O) {std::cout << "o wins\n"; return true;}
 if (board.board[3] == STATE::O && board.board[4] == STATE::O && board.board[5] == STATE::O) {std::cout << "o wins\n"; return true;}
if (board.board[6] == STATE::O && board.board[7] == STATE::O && board.board[8] == STATE::O) {std::cout << "o wins\n"; return true;}
if (board.board[0] == STATE::O && board.board[3] == STATE::O && board.board[6] == STATE::O) {std::cout << "o wins\n"; return true;}
 if (board.board[1] == STATE::O && board.board[4] == STATE::O && board.board[7] == STATE::O) {std::cout << "o wins\n"; return true;}
if (board.board[2] == STATE::O && board.board[5] == STATE::O && board.board[8] == STATE::O) {std::cout << "o wins\n"; return true;}
 if (board.board[0] == STATE::O && board.board[4] == STATE::O && board.board[8] == STATE::O) {std::cout << "o wins\n"; return true;}
if (board.board[6] == STATE::O && board.board[4] == STATE::O && board.board[2] == STATE::O) {std::cout << "o wins\n"; return true;}
for (auto it: board.board) {if (it == STATE::NONE) { return false;}}cout <<   "draw\n";return true;}
int main() {Board board;bool x_turn{true};while (!check_winner(board)) {board.display();print_turn(x_turn);int num; cin >> num;
board.set(num,x_turn);system("clear");x_turn=!x_turn; }}