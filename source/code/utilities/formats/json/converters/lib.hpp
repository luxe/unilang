#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "nlohmann/json.hpp"
#include "code/utilities/streams/filestreams/lib.hpp"
#include "code/utilities/streams/filestreams/read_all/lib.hpp"
#include "code/utilities/formats/json/converters/type_to_json_string.hpp"

template<typename T>
T From_JSON_String(std::string const& str){
    auto j = nlohmann::json::parse(str);
    auto t = j.get<T>();
    return t;
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

nlohmann::json Read_Json_From_File(std::string const& path);
std::vector<std::string> Read_Jsons_From_File(std::string const& path);


template <typename T>
void Print_Json(T const& t){
    auto str = Type_To_Json_String::As_JSON_String(t);
    std::cout << str << std::endl;
}


//validating json
bool Is_Valid_JSON_File(std::string const& file_name);
bool Is_Valid_JSON_String(std::string const& json_string);


//json serialization test function
//test the idempotency of going back and forth between serializations
//this makes it easy to compare the two strings for equivalence regardless of what the object is
//(the object might not have available ways to check equality)
template <typename T>
std::pair<std::string,std::string> json_serialize_deserialize_serialize(T obj){
    
    std::pair<std::string,std::string> results;
    
    //serialize
    nlohmann::json j = obj;
    results.first = j.dump();
    
    //deserialize
    T obj2 = j.get<T>();
    
    //serialize
    nlohmann::json j2 = obj2;
    results.second = j2.dump();
    
    return results;
}
