#include "code/utilities/types/strings/creators/lib.hpp"

std::string Create_String_Of_N_Chars(unsigned int const& num_of_chars, char const& c){
  return std::string(num_of_chars,c);
}

std::string Create_String_Of_N_Spaces(unsigned int num_spaces){
  return Create_String_Of_N_Chars(num_spaces, ' ');
}
std::string Char_To_String(unsigned char c){
  std::string str;
  str += c;
  return str;
}
std::string Chars_To_String(std::vector<char> chars){
  std::string str;
  for (auto it: chars){
    str+=it;
  }
  return str;
}
