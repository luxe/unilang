#include <string>

//add static casts to and from all classes
std::string as_string(std::wstring const& wstr);
std::wstring as_wstring(std::string const& str);

//dummies
std::string as_string(std::string const& s);
std::wstring as_wstring(std::wstring const& s);
