#pragma once
#include <string>

//base colorizing string functions
std::string colorize(std::string const& message, int const& background, int const& forground);
std::string colorize_forground(std::string const& message, int const& background);
std::string colorize_background(std::string const& message, int const& forground);

std::string colorize_rgb(std::string const& message, int r, int g, int b);

//specific colorizing string functions
std::string Green_String(std::string const& str);
std::string Red_String(std::string const& str);
std::string Gold_String(std::string const& str);
std::string Blue_String(std::string const& str);
std::string Teal_String(std::string const& str);
std::string White_String(std::string const& str);
std::string Black_String(std::string const& str);

//output string through std::cout
void Green_Message(std::string const& str);
void Red_Message(std::string const& str);
void Gold_Message(std::string const& str);
void Blue_Message(std::string const& str);
void Teal_Message(std::string const& str);
void White_Message(std::string const& str);
void Black_Message(std::string const& str);
void Purple_Message(std::string const& str);

//output string through std::cout and flush
void Green_Message_And_Flush(std::string const& str);
void Red_Message_And_Flush(std::string const& str);
void Gold_Message_And_Flush(std::string const& str);
void Blue_Message_And_Flush(std::string const& str);
void Teal_Message_And_Flush(std::string const& str);
void White_Message_And_Flush(std::string const& str);
void Black_Message_And_Flush(std::string const& str);
void Purple_Message_And_Flush(std::string const& str);

//output string through std::cerr
void Green_Error_Message(std::string const& str);
void Red_Error_Message(std::string const& str);
void Gold_Error_Message(std::string const& str);
void Blue_Error_Message(std::string const& str);
void Teal_Error_Message(std::string const& str);
void White_Error_Message(std::string const& str);
void Black_Error_Message(std::string const& str);
void Purple_Error_Message(std::string const& str);

//output string through std::cerr and flush
void Green_Error_Message_And_Flush(std::string const& str);
void Red_Error_Message_And_Flush(std::string const& str);
void Gold_Error_Message_And_Flush(std::string const& str);
void Blue_Error_Message_And_Flush(std::string const& str);
void Teal_Error_Message_And_Flush(std::string const& str);
void White_Error_Message_And_Flush(std::string const& str);
void Black_Error_Message_And_Flush(std::string const& str);
void Purple_Error_Message_And_Flush(std::string const& str);

void Green_Then_Regular_Message(std::string const& green, std::string const& regular);
void Red_Then_Regular_Message(std::string const& green, std::string const& regular);
void Gold_Then_Regular_Message(std::string const& green, std::string const& regular);
void Blue_Then_Regular_Message(std::string const& green, std::string const& regular);
void Teal_Then_Regular_Message(std::string const& green, std::string const& regular);
void White_Then_Regular_Message(std::string const& green, std::string const& regular);
void Black_Then_Regular_Message(std::string const& green, std::string const& regular);
void Purple_Then_Regular_Message(std::string const& green, std::string const& regular);

////////////////////////////////////////// SAME, BUT FOR WSTRING //////////////////////////////////////////////////////////////

//base colorizing wstring functions
std::wstring colorize(std::wstring const& message, int const& background, int const& forground);
std::wstring colorize_forground(std::wstring const& message, int const& background);
std::wstring colorize_background(std::wstring const& message, int const& forground);

//specific colorizing wstring functions
std::wstring Green_wString(std::wstring const& str);
std::wstring Red_wString(std::wstring const& str);
std::wstring Gold_wString(std::wstring const& str);
std::wstring Blue_wString(std::wstring const& str);
std::wstring Teal_wString(std::wstring const& str);
std::wstring White_wString(std::wstring const& str);
std::wstring Black_wString(std::wstring const& str);

//output wstring through std::cout
void Green_Message(std::wstring const& str);
void Red_Message(std::wstring const& str);
void Gold_Message(std::wstring const& str);
void Blue_Message(std::wstring const& str);
void Teal_Message(std::wstring const& str);
void White_Message(std::wstring const& str);
void Black_Message(std::wstring const& str);

//output wstring through std::cout and flush
void Green_Message_And_Flush(std::wstring const& str);
void Red_Message_And_Flush(std::wstring const& str);
void Gold_Message_And_Flush(std::wstring const& str);
void Blue_Message_And_Flush(std::wstring const& str);
void Teal_Message_And_Flush(std::wstring const& str);
void White_Message_And_Flush(std::wstring const& str);
void Black_Message_And_Flush(std::wstring const& str);

//output wstring through std::cerr
void Green_Error_Message(std::wstring const& str);
void Red_Error_Message(std::wstring const& str);
void Gold_Error_Message(std::wstring const& str);
void Blue_Error_Message(std::wstring const& str);
void Teal_Error_Message(std::wstring const& str);
void White_Error_Message(std::wstring const& str);
void Black_Error_Message(std::wstring const& str);

//output wstring through std::cerr and flush
void Green_Error_Message_And_Flush(std::wstring const& str);
void Red_Error_Message_And_Flush(std::wstring const& str);
void Gold_Error_Message_And_Flush(std::wstring const& str);
void Blue_Error_Message_And_Flush(std::wstring const& str);
void Teal_Error_Message_And_Flush(std::wstring const& str);
void White_Error_Message_And_Flush(std::wstring const& str);
void Black_Error_Message_And_Flush(std::wstring const& str);

