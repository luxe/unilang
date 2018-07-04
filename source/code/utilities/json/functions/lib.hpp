#pragma once
#include <string>
#include "code/utilities/json/nlohmann/lib.hpp"

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

//validating json
bool Is_Valid_JSON_File(std::string const& file_name);
bool Is_Valid_JSON_String(std::string const& json_string);
