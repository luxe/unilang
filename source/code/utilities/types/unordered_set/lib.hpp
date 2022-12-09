#pragma once
#include <unordered_set>
#include <set>

//forward declerations
template <typename T>
void Add_To_Set(std::unordered_set<T> & s, T const& item_to_add);
template <typename T>
void Delete_From_Set(std::unordered_set<T> & s, T const& item_to_delete);
template <typename T>
bool Exists_In_Set(std::unordered_set<T> const& s, T const& item);

//set functions
template <typename T>
void Add_To_Set(std::unordered_set<T> & s, T const& item_to_add){
  s.insert(item_to_add);
}
template <typename T>
void Delete_From_Set(std::unordered_set<T> & s, T const& item_to_delete){
  if (Exists_In_Set(s,item_to_delete)){
    s.erase(s.find(item_to_delete));
  }
}
template <typename T>
bool Exists_In_Set(std::unordered_set<T> const& s, T const& item){
  return s.count(item);
}

template <typename T>
std::set<T> To_Set(std::unordered_set<T> const& uset){

    std::set<T> s;
    for(auto val:uset) { s.insert(val); }
    return s;
}

std::unordered_set<char> Create_From_String(std::string const& str);
std::unordered_set<char> Get_Intersection(std::unordered_set<char> const& a, std::unordered_set<char> const& b);
