#pragma once
#include <string>

//APPENDING
//appending to string
std::string& Append_With_Newline(std::string & str, std::string const& part);
std::string& Append(std::string & str, std::string const& part);
std::string& Append(std::string & str, char const& part);
std::string& Append_N_Times(std::string & str, std::string const& part, unsigned int number_of_times);

//appending to wstring
std::string& Append_With_Newline(std::string & str, std::wstring const& part);
std::string& Append(std::string & str, std::wstring const& part);
std::string& Append_N_Times(std::string & str, std::wstring const& part, unsigned int number_of_times);