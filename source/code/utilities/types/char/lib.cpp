#include "code/utilities/language_basic/control_structures/looping/lib.hpp"
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
    if (c == '8'){ return 8;}   if (c == '9'){ return 9;}
    return 0;
}
