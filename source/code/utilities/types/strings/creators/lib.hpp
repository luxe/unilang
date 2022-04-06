#pragma once
#include <string>
#include <vector>

//by conversion
std::string Char_To_String(unsigned char c);
std::string Chars_To_String(std::vector<char> chars);

//by repeating
std::string Create_String_Of_N_Chars(unsigned int const& num_of_chars, char const& c);
std::string Create_String_Of_N_Strs(unsigned int const& num_of_chars, std::string const& c);
std::string Create_String_Of_N_Spaces(unsigned int num_spaces);

//xml creation
std::string Start_Tag(std::string const& tag_name, std::string const& key, std::string const& value);
std::string Tag_Content(std::string const& tag_name,std::string const& content);
std::string Single_End_Tag(std::string const& tag_name);
std::string Single_End_Tag(std::string const& tag_name, std::string const& key, std::string const& value);
std::string End_Tag(std::string const& tag_name);
std::string Create_XML_Attribute_Equals_Quoted_Value(std::string const& key, std::string const& value);

std::string CreateStaircase(int size);


