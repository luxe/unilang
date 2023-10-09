#include "code/utilities/language_basic/control_structures/looping/lib.hpp"
#include "code/utilities/types/vectors/operators/lib.hpp"
#include "lib.hpp"
#include <iostream>
#include <bitset>
#include <string>

//transformers
void Print_Character_N_Times(char const& c, unsigned int const& amount){
  repeat([&]{std::cout << c;},amount);
}

//observers
bool Is_A_Control_Character(char const& c){
  return iscntrl(c);
}
bool Is_A_Printable_Character(char const& c){
  return isprint(c);
}
bool Is_A_Whitespace_Character(char const& c){
  return isspace(c);
}
bool Is_A_Blank_Character(char const& c){
  return isblank(c);
}
bool Is_A_Graphical_Character(char const& c){
  return isgraph(c);
}
bool Is_A_Puncuation_Character(char const& c){
  return ispunct(c);
}
bool Is_An_Alphanumberic_Character(char const& c){
  return isalnum(c);
}
bool Is_An_Alpha_Character(char const& c){
  return isalpha(c);
}

bool Is_An_Uppercase_Character(char const& c){
  return isupper(c);
}

bool Is_A_Lowercase_Character(char const& c){
  return islower(c);
}

bool Is_A_Numeric_Character(char const& c){
  return isdigit(c);
}

bool Is_A_Hexidecimal_Character(char const& c){
  return isxdigit(c);
}

char Get_Double_Quote(){
  return '"';
}
char Get_Single_Quote(){
  return '\'';
}
char Get_Forward_Slash()
{
	return '/';
}
char Get_Back_Slash()
{
	return '\\';
}


std::vector<char> Get_Lowercase_Letters(){
  std::vector<char> x;
  x.emplace_back('a');
  x.emplace_back('b');
  x.emplace_back('c');
  x.emplace_back('d');
  x.emplace_back('e');
  x.emplace_back('f');
  x.emplace_back('g');
  x.emplace_back('h');
  x.emplace_back('i');
  x.emplace_back('j');
  x.emplace_back('k');
  x.emplace_back('l');
  x.emplace_back('m');
  x.emplace_back('n');
  x.emplace_back('o');
  x.emplace_back('p');
  x.emplace_back('q');
  x.emplace_back('r');
  x.emplace_back('s');
  x.emplace_back('t');
  x.emplace_back('u');
  x.emplace_back('v');
  x.emplace_back('w');
  x.emplace_back('x');
  x.emplace_back('y');
  x.emplace_back('z');
  return x;
}
std::vector<char> Get_Uppercase_Letters(){
  std::vector<char> x;
  x.emplace_back('A');
  x.emplace_back('B');
  x.emplace_back('C');
  x.emplace_back('D');
  x.emplace_back('E');
  x.emplace_back('F');
  x.emplace_back('G');
  x.emplace_back('H');
  x.emplace_back('I');
  x.emplace_back('J');
  x.emplace_back('K');
  x.emplace_back('L');
  x.emplace_back('M');
  x.emplace_back('N');
  x.emplace_back('O');
  x.emplace_back('P');
  x.emplace_back('Q');
  x.emplace_back('R');
  x.emplace_back('S');
  x.emplace_back('T');
  x.emplace_back('U');
  x.emplace_back('V');
  x.emplace_back('W');
  x.emplace_back('X');
  x.emplace_back('Y');
  x.emplace_back('Z');
  return x;
}

char Get_Next_Capital_Letter(char c)
{
  if (c == 'A') { return 'B'; }
  if (c == 'B') { return 'C'; }
  if (c == 'C') { return 'D'; }
  if (c == 'D') { return 'E'; }
  if (c == 'E') { return 'F'; }
  if (c == 'F') { return 'G'; }
  if (c == 'G') { return 'H'; }
  if (c == 'H') { return 'I'; }
  if (c == 'I') { return 'J'; }
  if (c == 'J') { return 'K'; }
  if (c == 'K') { return 'L'; }
  if (c == 'L') { return 'M'; }
  if (c == 'M') { return 'N'; }
  if (c == 'N') { return 'O'; }
  if (c == 'O') { return 'P'; }
  if (c == 'P') { return 'Q'; }
  if (c == 'Q') { return 'R'; }
  if (c == 'R') { return 'S'; }
  if (c == 'S') { return 'T'; }
  if (c == 'T') { return 'U'; }
  if (c == 'U') { return 'V'; }
  if (c == 'V') { return 'W'; }
  if (c == 'W') { return 'X'; }
  if (c == 'X') { return 'Y'; }
  if (c == 'Y') { return 'Z'; }
  if (c == 'Z') { return 'A'; }
  return c;
}

std::vector<char> Get_All_Cased_Letters(){
  auto x = Get_Lowercase_Letters();
  x += Get_Uppercase_Letters();
  return x;
}

wchar_t Zero_Width_Space(){
	return L'\u200B';
}
wchar_t Zero_Width_Non_Breaking_Space(){
	return L'\uFEFF';
}
wchar_t Zero_Width_Joiner(){
	return L'\u200D';
}
wchar_t Zero_Width_Non_Joiner(){
	return L'\u200C';
}

std::string As_4_Bit_Binary(const char c)
{
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
    return "?";
}
std::string Hex_To_4_Bit_Binary_Segments(std::string const& s)
{
  std::string str;
  for (auto const& it: s){
    str += As_4_Bit_Binary(it);
  }
  return str;
}
std::string As_Binary(const char c){
	int as_int = static_cast<int>(c);
	return std::bitset<8>(as_int).to_string();
}
std::string As_Binary(const uint8_t c){
  return std::bitset<8>(c).to_string();
}
std::string As_256_Bit_Binary(const uint8_t z1, const uint8_t z2, const uint8_t z3, const uint8_t z4, const uint8_t z5, const uint8_t z6, const uint8_t z7, const uint8_t z8, 
                              const uint8_t z9, const uint8_t z10, const uint8_t z11, const uint8_t z12, const uint8_t z13, const uint8_t z14, const uint8_t z15, const uint8_t z16,
                              const uint8_t z17, const uint8_t z18, const uint8_t z19, const uint8_t z20, const uint8_t z21, const uint8_t z22, const uint8_t z23, const uint8_t z24, 
                              const uint8_t z25, const uint8_t z26, const uint8_t z27, const uint8_t z28, const uint8_t z29, const uint8_t z30, const uint8_t z31, const uint8_t z32){
  std::string x;
  x += std::bitset<8>(z1).to_string(); // 8
  x += std::bitset<8>(z2).to_string(); // 16
  x += std::bitset<8>(z3).to_string();
  x += std::bitset<8>(z4).to_string(); // 32
  x += std::bitset<8>(z5).to_string();
  x += std::bitset<8>(z6).to_string();
  x += std::bitset<8>(z7).to_string();
  x += std::bitset<8>(z8).to_string(); // 64
  
  x += std::bitset<8>(z9).to_string();
  x += std::bitset<8>(z10).to_string();
  x += std::bitset<8>(z11).to_string();
  x += std::bitset<8>(z12).to_string();
  x += std::bitset<8>(z13).to_string();
  x += std::bitset<8>(z14).to_string();
  x += std::bitset<8>(z15).to_string();
  x += std::bitset<8>(z16).to_string(); // 128
  
  x += std::bitset<8>(z17).to_string();
  x += std::bitset<8>(z18).to_string();
  x += std::bitset<8>(z19).to_string();
  x += std::bitset<8>(z20).to_string();
  x += std::bitset<8>(z21).to_string();
  x += std::bitset<8>(z22).to_string();
  x += std::bitset<8>(z23).to_string();
  x += std::bitset<8>(z24).to_string();
  
  x += std::bitset<8>(z25).to_string();
  x += std::bitset<8>(z26).to_string();
  x += std::bitset<8>(z27).to_string();
  x += std::bitset<8>(z28).to_string();
  x += std::bitset<8>(z29).to_string();
  x += std::bitset<8>(z30).to_string();
  x += std::bitset<8>(z31).to_string();
  x += std::bitset<8>(z32).to_string(); // 256
  return x;
}

std::string As_256_Bit_Binary(const uint16_t z1, const uint16_t z2, const uint16_t z3, const uint16_t z4, const uint16_t z5, const uint16_t z6, const uint16_t z7, const uint16_t z8, 
                              const uint16_t z9, const uint16_t z10, const uint16_t z11, const uint16_t z12, const uint16_t z13, const uint16_t z14, const uint16_t z15, const uint16_t z16){
  std::string x;
  x += std::bitset<16>(z1).to_string(); // 16
  x += std::bitset<16>(z2).to_string(); // 32
  x += std::bitset<16>(z3).to_string();
  x += std::bitset<16>(z4).to_string(); // 64
  x += std::bitset<16>(z5).to_string();
  x += std::bitset<16>(z6).to_string();
  x += std::bitset<16>(z7).to_string();
  x += std::bitset<16>(z8).to_string(); // 128
  
  x += std::bitset<16>(z9).to_string();
  x += std::bitset<16>(z10).to_string();
  x += std::bitset<16>(z11).to_string();
  x += std::bitset<16>(z12).to_string();
  x += std::bitset<16>(z13).to_string();
  x += std::bitset<16>(z14).to_string();
  x += std::bitset<16>(z15).to_string();
  x += std::bitset<16>(z16).to_string(); // 256
  return x;
}

std::string As_256_Bit_Binary(const uint32_t z1, const uint32_t z2, const uint32_t z3, const uint32_t z4, const uint32_t z5, const uint32_t z6, const uint32_t z7, const uint32_t z8){
  
  std::string x;
  x += std::bitset<32>(z1).to_string(); // 32
  x += std::bitset<32>(z2).to_string(); // 64
  x += std::bitset<32>(z3).to_string();
  x += std::bitset<32>(z4).to_string(); // 128
  x += std::bitset<32>(z5).to_string();
  x += std::bitset<32>(z6).to_string();
  x += std::bitset<32>(z7).to_string();
  x += std::bitset<32>(z8).to_string(); // 256
  return x;
  
}
char From_Binary(std::string const& str){
	std::bitset<8> bs;

	char binary_one = '1';
	char binary_zero = '0';

	size_t j = 0;
	for (size_t i = bs.size()-1; i > 0; --i){
		if (str[i] == binary_one){
			bs.set(j);
		}else if (str[i] == binary_zero){
			bs.reset(j);
		}
		++j;
	}
	
	auto c = bs.to_ulong();
	return static_cast<char>(c);
}


int as_number(char const& c){
  if (c == '0'){ return 0;}
    if (c == '1'){ return 1;}
    if (c == '2'){ return 2;}
    if (c == '3'){ return 3;}
    if (c == '4'){ return 4;}
    if (c == '5'){ return 5;}
    if (c == '6'){ return 6;}
    if (c == '7'){ return 7;}
    if (c == '8'){ return 8;}
    if (c == '9'){ return 9;}
    return 0;
}

std::map<std::string,double> Standard_Char_Likelyhood_In_Words()
{
    //These can be generated off of word lists
    std::map<std::string,double> char_likelyhood;
    char_likelyhood.insert({"A",7.731310380600402});
    char_likelyhood.insert({"B",1.8591674378486283});
    char_likelyhood.insert({"C",4.00857436453624});
    char_likelyhood.insert({"D",3.3550443159468637});
    char_likelyhood.insert({"E",11.280240648067918});
    char_likelyhood.insert({"F",1.1918838256126723});
    char_likelyhood.insert({"G",2.802386832731124});
    char_likelyhood.insert({"H",2.499729840714085});
    char_likelyhood.insert({"I",9.033969337412247});
    char_likelyhood.insert({"J",0.16661459960429031});
    char_likelyhood.insert({"K",0.938110928385194});
    char_likelyhood.insert({"L",5.229851520456461});
    char_likelyhood.insert({"M",2.8964219121776016});
    char_likelyhood.insert({"N",6.692169703257041});
    char_likelyhood.insert({"O",6.629846411989964});
    char_likelyhood.insert({"P",3.0010668835800134});
    char_likelyhood.insert({"Q",0.16901164926840867});
    char_likelyhood.insert({"R",6.983077222330286});
    char_likelyhood.insert({"S",9.62828047052906});
    char_likelyhood.insert({"T",6.522725799131168});
    char_likelyhood.insert({"U",3.3091860051595514});
    char_likelyhood.insert({"V",0.9202312956446393});
    char_likelyhood.insert({"W",0.7690206873245193});
    char_likelyhood.insert({"X",0.28355918649635825});
    char_likelyhood.insert({"Y",1.616004432577084});
    char_likelyhood.insert({"Z",0.48251430861817945});
    return char_likelyhood;
}
