#pragma once
#include <set>

//forward declerations
template <typename T>
void Add_To_Set(std::set<T> & s, T const& item_to_add);

template <typename T>
void Delete_From_Set(std::set<T> & s, T const& item_to_delete);

template <typename T>
bool Exists_In_Set(std::set<T> const& s, T const& item);

//functions
template <typename T>
void Add_To_Set(std::set<T> & s, T const& item_to_add){
  s.insert(item_to_add);
}

template <typename T>
void Delete_From_Set(std::set<T> & s, T const& item_to_delete){
  if (Exists_In_Set(s,item_to_delete)){
    s.erase(s.find(item_to_delete));
  }
}

template <typename T>
bool Exists_In_Set(std::set<T> const& s, T const& item){
  return s.count(item);
}
