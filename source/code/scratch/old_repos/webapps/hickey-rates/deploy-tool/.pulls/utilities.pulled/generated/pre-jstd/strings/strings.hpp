#pragma once


//transforming string functions
std::string& ltrim(std::string &s);
std::string& rtrim(std::string &s);
std::string&  trim(std::string &s);
std::string& Squeeze_Away_Spaces(std::string &s);
std::string& Remove_Suffix(std::string &s);
std::string As_Removed_Suffix(std::string s);

	//casing
	std::string& Uppercase(std::string &s);
	std::string& Lowercase(std::string &s);
	std::string As_Uppercase(std::string s);
	std::string As_Lowercase(std::string s);

	//basically: trim->squeeze away spaces->turn spaces into underscores->capitalize each word
	std::string Make_Capital_And_Underscored_In_User_Type_Format(std::string s);
	std::string As_All_Capital_Letters_With_Spaces_As_Underscores(std::string s);

std::string string_replace_first_instance( std::string src, std::string const& target, std::string const& repl);
std::string string_replace_all( std::string src, std::string const& target, std::string const& repl);
std::string& replace_all( std::string & src, char const& c1, char const& c2);

std::string& Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(std::string & str);

//observing string functions
bool Space_At_The_Beginning(std::string const& s);
bool Space_At_The_End(std::string const& s);
bool Consecutive_Space_In_The_Middle(std::string s);
bool Contains_Capital_Letters(std::string const& s);
bool Contains_Character(std::string const& s, char const& c);

bool First_Char_Comes_Before_Second_Char(std::string const& s, char const& c1, char const& c2);

std::vector<size_t> Get_Indexes_Of_Character(std::string const& s, char const& c);
unsigned int Count_Instances_Of_Character(std::string const& s, char const& c);


//converting to other types
unsigned int as_unsigned(std::string str);
signed int as_signed(std::string str);
std::vector<std::string> Put_Each_Line_Of_String_Into_A_Vector(std::string const& str);
