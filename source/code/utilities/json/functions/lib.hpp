#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "code/utilities/streams/filestreams/lib.hpp"
#include "code/utilities/streams/filestreams/read_all/lib.hpp"

//json append for all types that don't derive from an hcp file construct
//so we assume the json library can handle all basic types and std containers
//the function will either return a basic type, a std container, or call an overload that returns a json
template <typename T>
T As_JSON_Assignable(T const& t){
  return t;
}
template <typename T>
std::string As_JSON_String(T const& t){
    auto j = As_JSON_Assignable(t);
    nlohmann::json r = j;
    return r.dump(2);
}
template <typename T>
std::string As_JSON_String_Indented_N_Spaces(T const& t, unsigned int const& number_of_spaces){
    auto j = As_JSON_Assignable(t);
    nlohmann::json r = j;
    return r.dump(number_of_spaces);
}
template <typename T>
std::string As_Minified_JSON_String(T const& t){
    auto j = As_JSON_Assignable(t);
    nlohmann::json r = j;
    return r.dump();
}
template <typename T>
void Write_Json_To_File(T const& t, std::string const& path){
    nlohmann::json j = t;
    auto str = j.dump(2);
    std::ofstream outfile(path);
    outfile << str;
    outfile.close();
}
template <typename T>
void Read_Json_From_File(T & t, std::string const& path){
    auto str = Read_Entire_File_Into_String(path);
    auto j = nlohmann::json::parse(str);
    t = j.get<T>();
}

template <typename T>
void Print_Json(T const& t){
    auto str = As_JSON_String(t);
    std::cout << str << std::endl;
}


//validating json
bool Is_Valid_JSON_File(std::string const& file_name);
bool Is_Valid_JSON_String(std::string const& json_string);
