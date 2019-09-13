#pragma once
#include <string>
#include <vector>

std::string Create_String_Of_N_Chars(unsigned int const& num_of_chars, char const& c);
std::string Create_String_Of_N_Strs(unsigned int const& num_of_chars, std::string const& c);
std::string Create_String_Of_N_Spaces(unsigned int num_spaces);
std::string Char_To_String(unsigned char c);
std::string Chars_To_String(std::vector<char> chars);
std::string Create_XML_Attribute_Equals_Quoted_Value(std::string const& key, std::string const& value);


