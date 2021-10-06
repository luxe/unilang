#include "nlohmann/json.hpp"
#include "code/utilities/streams/filestreams/lib.hpp"
#include <iostream>

bool Is_Valid_JSON_String(std::string const& json_string){
  bool valid = true;
  try{
    nlohmann::json::parse(json_string);
  }catch(...){
    valid = false;
  }
  
  return valid;
}