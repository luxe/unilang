#pragma once
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

template <typename T>
class Unique_Counter{
  std::map<T,int> hash_table;
  
  public:
  void Add(T const& t){
    auto search = hash_table.find(t);
    if(search != hash_table.end()) {
      search->second++;
    }
    else{
      hash_table.emplace(t,1);
    }
  }
  
  T Most_Common(){
    auto it = std::max_element(hash_table.begin(),hash_table.end(),[](auto x, auto y){
      return x.second < y.second;
    });
    return it->first;
  }
  
  T Least_Common(){
    auto it = std::min_element(hash_table.begin(),hash_table.end(),[](auto x, auto y){
      return x.second < y.second;
    });
    return it->first;
  }
};
