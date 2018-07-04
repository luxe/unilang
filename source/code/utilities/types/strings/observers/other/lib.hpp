#pragma once
#include <string>
#include <vector>
#include <utility>


//searching
bool Contains_Character(std::string const& s, char const& c);
bool Begins_With(std::string const& str, std::string const& start_part);
bool Ends_With(std::string const& str, std::string const& end_part);
bool Begins_And_Ends_With(std::string const& str, std::string const& part);
bool Begins_Or_Ends_With(std::string const& str, std::string const& part);
bool Begins_With(std::string const& str, char const& start_part);
bool Ends_With(std::string const& str, char const& end_part);
bool Begins_And_Ends_With(std::string const& str, char const& part);
bool Contains_Substring(std::string const& str, std::string const& part);
std::string Get_Substring_Found_Between_First_Instance_Of_Two_Characters(std::string str, char first, char last);

//scanning from the front
std::string Get_All_Beginning_Characters_Until_Capital_Letter(std::string const& str);
bool First_Char_Comes_Before_Second_Char(std::string const& s, char const& c1, char const& c2);