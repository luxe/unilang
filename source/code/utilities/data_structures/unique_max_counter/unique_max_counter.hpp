#pragma once
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <functional>


//TODO: turn into global functions
template <typename T>
class Unique_Max_Counter{
  
  public:
  //thing to count, current amount, max
  std::map<T,std::pair<int,int>> hash_table;
  
  void Add(T const& t, int max){
    auto search = hash_table.find(t);
    if(search != hash_table.end()) {
      search->second.first++;
      //assume max was already set
    }
    else{
      hash_table.emplace(t,std::pair<int,int>{1,max});
    }
  }
  
  bool At_Max(T const& t){
    auto search = hash_table.find(t);
    if(search != hash_table.end()) {
      if (search->second.first >= search->second.second){
        return true;
      }
    }
    return false;
  }
  
};
