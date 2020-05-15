#include <string>
#include "nlohmann/json.hpp"
#include <sstream>
#include "gtest/gtest.h"
#include "src/tree.hh"


//TREE SERIALIZATION
template <typename T>
std::vector<std::pair<int,T>> to_depth_list(tree<T> const& tr){
    std::vector<std::pair<int,T>> depth_list;
    for (auto it = tr.begin(); it != tr.end(); ++it){
        auto depth = tr.depth(it);
        T obj = *it;
        depth_list.emplace_back(std::pair<int,T>{depth,obj});
    }
    return depth_list;
}
template <typename T>
tree<T> from_depth_list(std::vector<std::pair<int,T>> const& depth_list){
    tree<T> tr;
    auto top = tr.begin();
    auto current_node = tr.begin();
    int previous_depth = 0;
    for (auto const& it: depth_list){
        
        //at root
        if (it.first == 0){
            current_node = tr.insert(top,it.second);
        }
        
        //go deeper
        else if (previous_depth < it.first){
            current_node = tr.append_child(current_node,it.second);
            
        }
        //climb higher
        else {
            while (previous_depth >= it.first){
                current_node = tr.parent(current_node);
                previous_depth--;
            }
            current_node = tr.append_child(current_node,it.second);
        }
        previous_depth = it.first;
    }
    return tr;
}


//SERIALIZE TEST OBJECT
struct foo{
    int i;
};

void to_json(nlohmann::json& j, const foo& f) {
    j = nlohmann::json{{"i", f.i}};
}

void from_json(const nlohmann::json& j, foo& f) {
    j.at("i").get_to(f.i);
}

//SERIALIZE TEST TREE
template <typename T>
void to_json(nlohmann::json& j, tree<T> const& tr) {
    auto depth_list = to_depth_list(tr);
    j = depth_list;
}

template <typename T>
void from_json(const nlohmann::json& j, tree<T> & tr) {
    auto depth_list = j.get<std::vector<std::pair<int,T>>>();
    tr = from_depth_list(depth_list);
}


tree<foo> Build_Tree() {
    tree<foo> tr;
    auto top = tr.begin();
    
    foo f;
    f.i = 1;
    auto f1=tr.insert(top,f);
    f.i = 2;
    auto f2=tr.insert(top,f);
    f.i = 3;
    auto f3=tr.insert(top,f);
    f.i = 4;
    auto f4=tr.append_child(f2,f);
    f.i = 5;
    auto f5=tr.append_child(f4,f);
    f.i = 6;
    auto f6=tr.append_child(f5,f);
    
    return tr;
}

TEST(Serialization, TreeNonIntrusive) {
    
    auto tr = Build_Tree();
    nlohmann::json j = tr;
    auto f2 = j.get<tree<foo>>();
    //EXPECT_EQ(f.i,f2.i);
}