#pragma once
#include <string>
#include <vector>
#include <utility>

std::string Get_As_String_With_Element_On_Each_Line(std::vector<std::string> const& vec);
std::string Get_As_String_With_Space_In_Between_Each_Element(std::vector<std::string> v);
std::string Get_As_String_With_Dot_In_Between_Each_Element(std::vector<std::string> v);
std::string Get_As_String_With_CommaSpace_In_Between_Each_Element(std::vector<std::string> v);
std::string Get_As_String_With_Comma_In_Between_Each_Element(std::vector<std::string> v);
std::string Get_As_String_With_Forward_Slash_In_Between_Each_Element(std::vector<std::string> v);
std::string Get_As_String_With_Delim_In_Between_Each_Element(std::vector<std::string> v, std::string const& delim);
std::vector<std::pair<char,int>> Get_As_Each_Element_A_Char_And_Int(std::vector<std::string> const& v);
std::vector<std::vector<int>> VecVecStringToVecVecInt(std::vector<std::vector<std::string>> const& lists);
std::vector<int> VecStringToVecInt(std::vector<std::string> const& list);
std::vector<long> VecStringToVecLong(std::vector<std::string> const& list);
std::vector<unsigned long> VecStringToVecULong(std::vector<std::string> const& list);

std::string Squeeze_Into_String(std::vector<std::string> v);

template <typename T>
std::vector<std::pair<T,T>> Turn_Into_Vector_Of_Pairs(std::vector<T> vec){
  
  std::vector<std::pair<T,T>> returned;
  std::pair<T,T> p;
  bool which = true;
  
  for (int i = 0; i < vec.size(); ++i){
    
    if (which){
      p.first = vec[i];
      which = false;
    }else{
      p.second = vec[i];
      which = true;
      returned.push_back(p);
    }
  }
  
  if (!which){
    p.second = T();
    returned.push_back(p);
  }
  
  return returned;
}

template <typename T>
std::vector<T> Convert_Pair_To_Two_Element_Vector(std::pair<T,T> p){
  std::vector<T> result;
  
  result.push_back(p.first);
  result.push_back(p.second);
  
  return result;
}
