#pragma once
#include <string>
#include <iostream>
#include "nlohmann/json.hpp"
#include <sstream>
#include "src/tree.hh"
#include "code/utilities/types/tree/converters/depth_list.hpp"

//overloads for nlohmann json serialization
template <typename T>
void to_json(nlohmann::json& j, tree<T> const& tr) {
    auto depth_list = to_depth_list(tr);
    //j = nlohmann::json{{"depth_list", depth_list}};
    j = depth_list;
}

template <typename T>
void from_json(const nlohmann::json& j, tree<T> & tr) {
    
     auto depth_list = j.get<std::vector<std::pair<int,T>>>();
     
     //If I assign directly to tr it segfaults
     tree<T> tr_new = from_depth_list(depth_list);
     tr = tr_new;
}