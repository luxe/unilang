#include "code/utilities/types/vectors/observers/lib.hpp"
#include "code/utilities/types/general/lib.hpp"

size_t Get_Longest_String_Length_In_Vector(std::vector<std::string> const& v){
    return (*max_element ( v.begin(), v.end())).length();
}
bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str){
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}

std::string Get_As_Comma_Seperated_String(std::vector<std::string> strs){
  std::string list;
  
  Call_Function_On_All_Elements_Except_Last_Element_Then_Call_Function_On_Last_Element(strs,
  [&](std::string str){list += str + ",";},[&](std::string str){list += str;});
  
  return list;
}
