#include "code/utilities/types/converters/lib.hpp"
#include <iostream>
#include <cassert>
#include <codecvt>
#include <locale>

//char* coverage
std::string as_string(const char* s){
   std::string str(s);
   return as_string(str);
}
std::wstring as_wstring(const char* s){
   std::string str(s);
   return as_wstring(str);
}

// Dummy overload
std::wstring as_wstring(std::wstring const& s){return s;}

// Real worker
std::wstring as_wstring(std::string const& s)
{
  const char * cs = s.c_str();
  const size_t wn = std::mbsrtowcs(NULL, &cs, 0, NULL);

  if (wn == size_t(-1))
  {
    std::cout << "Error in mbsrtowcs(): " << errno << std::endl;
    return L"";
  }

  std::vector<wchar_t> buf(wn + 1);
  const size_t wn_again = std::mbsrtowcs(buf.data(), &cs, wn + 1, NULL);

  if (wn_again == size_t(-1))
  {
    std::cout << "Error in mbsrtowcs(): " << errno << std::endl;
    return L"";
  }

  assert(cs == NULL); // successful conversion

  return std::wstring(buf.data(), wn);
}
std::wstring as_wstring2(std::string const& s)
{
  using convert_t = std::codecvt_utf8<wchar_t>;
  std::wstring_convert<convert_t, wchar_t> strconverter;
  return strconverter.from_bytes(s);
}


// Dummy
std::string as_string(std::string const& s){return s;}

// Real worker
std::string as_string(std::wstring const& s)
{
  const wchar_t * cs = s.c_str();
  const size_t wn = std::wcsrtombs(NULL, &cs, 0, NULL);

  if (wn == size_t(-1))
  {
    std::cout << "Error in wcsrtombs(): " << errno << std::endl;
    return "";
  }

  std::vector<char> buf(wn + 1);
  const size_t wn_again = std::wcsrtombs(buf.data(), &cs, wn + 1, NULL);

  if (wn_again == size_t(-1))
  {
    std::cout << "Error in wcsrtombs(): " << errno << std::endl;
    return "";
  }

  assert(cs == NULL); // successful conversion

  return std::string(buf.data(), wn);
}
