#include "code/utilities/types/vectors/creators/lib.hpp"
#include "code/utilities/streams/filestreams/read_all/lib.hpp"
#include "code/utilities/types/strings/transformers/trimming/lib.hpp"
#include "code/utilities/types/strings/observers/splitting/lib.hpp"

std::vector<std::string> Get_Comma_Seperated_Values_From_File(std::string const& path_to_file){
  auto all = Read_Entire_File_Into_String(path_to_file);
  auto parts = Split_Into_Parts_From_Comma(all);
  for (auto & it: parts){
    trim(it);
  }
  return parts;
}

std::vector<std::vector<std::string>> Create_N_By_N_Vector_Of_Question_Marks(int x, int y){
    std::string str = "?";
    std::vector<std::vector<std::string>> vec = Create_N_By_N_Vector(x,y,str);
    return vec;
}
std::vector<std::vector<std::string>> Create_N_By_N_Vector_Of_Strs(int x, int y, std::string const& str){
    std::vector<std::vector<std::string>> vec = Create_N_By_N_Vector(x,y,str);
    return vec;
}

std::vector<std::string> StringToVector(std::string const& str, char const delimiter){
  
  std::vector<std::string> vec;
  std::string element;
  
  
  //we are going to loop through each character of the string slowly building an element string.
  //whenever we hit a delimiter, we will push the element into the vector, and clear it to get ready for the next element
  for_each(begin(str),end(str),[&](char const ch){
    if(ch!=delimiter){
      element+=ch;
    }
    else{
      if (element.length()>0){
      vec.push_back(element);
      element.clear();
      }
    }
  });
  
  
  //push in the last element if the string does not end with the delimiter
  if (element.length()>0){
    vec.push_back(element);
  }
  
  
  return vec;
}