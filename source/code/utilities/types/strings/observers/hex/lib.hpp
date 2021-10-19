#pragma once
#include <string>
#include <vector>

//to hex
std::string AsHexString(int c);
std::string AsCapital2WidthHexString(int c);
std::string to_caps_hex(unsigned char *s);
std::string to_caps_hex(std::string const& str);
std::string to_caps_hex_p2(std::string const& str);
std::string string_to_hex(const std::string& input);

std::vector<std::string> Get_All_2_Width_Hex_For_1_Byte();

//from hex
std::string unhex(std::string const& str);
std::string hex_to_string(const std::string& input);
int hex_value(unsigned char hex_digit);


std::string hextobin(const std::string &s);
std::string bintohex(const std::string &s);


//for example: 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F
//is reindexed as F,E,D,C,B,A,9,8,7,6,5,4,3,2,1,0
std::string As_Caps_Hex_Reversed(std::string const& str);