#include "code/utilities/types/map/lib.hpp"

std::map<char,int> Count_Letters(std::string const& s){
  std::map<char,int> results;
  for (auto c: s){
    auto search = results.find(c);
    if(search != results.end()) {
      search->second++;
    }
    else{
      results.emplace(c,1);
    }
  }
  
  return results;
}