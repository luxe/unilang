#pragma once
#include <map>
#include <vector>



//converting
template <typename T>
std::map<T,std::vector<T>> Convert_To_Map(std::multimap<T,T> map){
    std::map<T,std::vector<T>> results;
    
    for(auto it = map.begin(), end = map.end(); it != end; ++it)
    {
      results[it->first].emplace_back(it->second);
    }

    return results;
}

template <typename T>
std::multimap<T,T> Convert_To_Mulimap(std::map<T,std::vector<T>> map){
    std::multimap<T,T> results;
    for (auto const& it: map){
        for (auto const& val: it.second){
            results.insert({it.first,val});
        }
    }
    return results;
}




//checking existence
template <typename T, typename U>
bool Exists(std::multimap<T,U> const& map, T const& item){
    if (map.find(item) != map.end()){
        return true;
    }
    return false;
}

template <typename T, typename U>
std::vector<T> Find_By_Value(std::multimap<T,U> const& map, U const& val){
    std::vector<T> results;
    for (auto const& it: map){
        if (it.second == val){
            results.emplace_back(it.first);
        }
    }
    return results;
}

template <typename T, typename U>
bool Value_Exists(std::multimap<T,U> const& map, U const& val){
    std::vector<T> results;
    for (auto const& it: map){
        if (it.second == val){
            return true;
        }
    }
    return false;
}
