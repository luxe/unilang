#include "nlohmann/json.hpp"
#include "code/utilities/streams/filestreams/lib.hpp"
#include <iostream>

bool Is_Valid_JSON_File(std::string const& file_name){
  bool valid = true;
  try{
    nlohmann::json::parse(Read_Entire_File_Into_String(file_name));
  }catch(...){
    valid = false;
  }
  
  return valid;
}
bool Is_Valid_JSON_String(std::string const& json_string){
  bool valid = true;
  try{
    nlohmann::json::parse(json_string);
  }catch(...){
    valid = false;
  }
  
  return valid;
}


std::vector<std::string> Read_Jsons_From_File(std::string const& path)
{
  std::vector<std::string> results;
  
  std::ifstream i(path);
  while (i){
    try{
      nlohmann::json j;
      i >> j;
      results.emplace_back(j.dump(0));
    }catch(...){
      return results;
    }
  }
  
  return results;
}