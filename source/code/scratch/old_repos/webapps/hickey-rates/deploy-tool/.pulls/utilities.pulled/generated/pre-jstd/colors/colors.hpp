#pragma once
#include <string>

//color functions
std::string colorize(std::string const& message, int const& background, int const& forground);
std::string colorize_forground(std::string const& message, int const& background);
std::string colorize_background(std::string const& message, int const& forground);
void Exit_With_Error_Message(std::string const& str);
void Green_Message(std::string const& str);
void Red_Message(std::string const& str);
