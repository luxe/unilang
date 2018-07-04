#pragma once
#include <string>

//search and replace
std::string string_replace_first_instance( std::string src, std::string const& target, std::string const& repl);
std::string string_replace_all( std::string src, std::string const& target, std::string const& repl);
std::string& replace_all( std::string & src, char const& c1, char const& c2);
std::string& Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(std::string & str);