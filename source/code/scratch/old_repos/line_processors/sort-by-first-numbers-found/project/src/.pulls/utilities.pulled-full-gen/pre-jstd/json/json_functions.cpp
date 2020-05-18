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
