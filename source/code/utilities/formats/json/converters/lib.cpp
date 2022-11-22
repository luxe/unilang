#include "nlohmann/json.hpp"
#include "code/utilities/streams/filestreams/lib.hpp"
#include <iostream>

bool Is_Valid_JSON_String(std::string const& json_string){
  bool valid = true;
  try{
    auto parsed_object = nlohmann::json::parse(json_string);
    (void)parsed_object;
  }catch(...){
    valid = false;
  }
  
  return valid;
}