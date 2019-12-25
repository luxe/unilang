#pragma once
#include <fstream>
#include <iostream>
#include "code/utilities/json/functions/lib.hpp"
#include <google/protobuf/util/json_util.h>

template <typename T>
void Serialize(T const& t, std::string const& path){
    std::ofstream ofs(path, std::ios_base::out | std::ios_base::binary);
    bool was_successful = t.SerializeToOstream(&ofs);
    if (!was_successful){
        std::cerr << "failed to serialize" << std::endl;
    }
}

template <typename T>
T Deserialize(std::string const& path){
    T t;
    std::ifstream ifs(path, std::ios_base::binary);
    bool was_successful = t.ParseFromIstream(&ifs);
    //bool was_successful = t.ParsePartialFromIstream(&ifs);
    if (!was_successful){
        std::cerr << "failed to deserialize" << std::endl;
    }
    return t;
}

template <typename T>
std::vector<T> Deserialize_Multiple_From_Json_File(std::string const& path){
    auto j_blobs = Read_Jsons_From_File(path);
    std::vector<T> results;
    for (auto const& it: j_blobs){
        T x;
        google::protobuf::util::JsonParseOptions options;
        JsonStringToMessage(it, &x, options);
        results.emplace_back(x);
    }
    
    return results;
}