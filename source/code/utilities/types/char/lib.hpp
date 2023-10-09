#pragma once
#include <string>
#include <map>

//observers
bool Is_A_Control_Character(char const& c);
bool Is_A_Printable_Character(char const& c);
bool Is_A_Whitespace_Character(char const& c);
bool Is_A_Blank_Character(char const& c);
bool Is_A_Graphical_Character(char const& c);
bool Is_A_Puncuation_Character(char const& c);
bool Is_An_Alphanumberic_Character(char const& c);
bool Is_An_Alpha_Character(char const& c);
bool Is_An_Uppercase_Character(char const& c);
bool Is_A_Lowercase_Character(char const& c);
bool Is_A_Numeric_Character(char const& c);
bool Is_A_Hexidecimal_Character(char const& c);

//printers
void Print_Character_N_Times(char const& c, unsigned int const& amount);

//get individuals
//the double/single quote functions exist because I've confused the syntax highlighter.  This is a work-around
//when working in hcp.  There's no reason they can't be functions though.  Everything should be a function.
//we'll add some more generators as necessary
char Get_Double_Quote();
char Get_Single_Quote();
char Get_Forward_Slash();
char Get_Back_Slash();

std::vector<char> Get_Lowercase_Letters();
std::vector<char> Get_Uppercase_Letters();
std::vector<char> Get_All_Cased_Letters();

char Get_Next_Capital_Letter(char c);

//get unicode characters (just easier)
wchar_t Zero_Width_Space();
wchar_t Zero_Width_Non_Breaking_Space();
wchar_t Zero_Width_Joiner();
wchar_t Zero_Width_Non_Joiner();

//converters
std::string As_4_Bit_Binary(const char c);
std::string Hex_To_4_Bit_Binary_Segments(std::string const& s);
std::string As_Binary(const char c);
std::string As_Binary(const uint8_t c);
std::string As_256_Bit_Binary(const uint8_t z1, const uint8_t z2, const uint8_t z3, const uint8_t z4, const uint8_t z5, const uint8_t z6, const uint8_t z7, const uint8_t z8, 
                              const uint8_t z9, const uint8_t z10, const uint8_t z11, const uint8_t z12, const uint8_t z13, const uint8_t z14, const uint8_t z15, const uint8_t z16,
                              const uint8_t z17, const uint8_t z18, const uint8_t z19, const uint8_t z20, const uint8_t z21, const uint8_t z22, const uint8_t z23, const uint8_t z24, 
                              const uint8_t z25, const uint8_t z26, const uint8_t z27, const uint8_t z28, const uint8_t z29, const uint8_t z30, const uint8_t z31, const uint8_t z32);

std::string As_256_Bit_Binary(const uint16_t z1, const uint16_t z2, const uint16_t z3, const uint16_t z4, const uint16_t z5, const uint16_t z6, const uint16_t z7, const uint16_t z8, 
                              const uint16_t z9, const uint16_t z10, const uint16_t z11, const uint16_t z12, const uint16_t z13, const uint16_t z14, const uint16_t z15, const uint16_t z16);

std::string As_256_Bit_Binary(const uint32_t z1, const uint32_t z2, const uint32_t z3, const uint32_t z4, const uint32_t z5, const uint32_t z6, const uint32_t z7, const uint32_t z8);

char From_Binary(std::string const& str);

int as_number(char const& c);

std::map<std::string,double> Standard_Char_Likelyhood_In_Words();


//character for bars
//█
//██████████████

//■
//■■■■■■■■■■■■
