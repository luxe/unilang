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