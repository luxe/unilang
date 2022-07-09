#pragma once
#include <utility>
#include <map>
#include <unordered_map>
#include <iostream>

//overloading on map type
template <typename X, typename Y>
bool Exists_In_Map(std::map<X,Y> const& m, X const& item);

template <typename X, typename Y>
bool Exists_In_Unordered_Map(std::unordered_map<X,Y> const& m, X const& item);

template <typename X, typename Y>
void Add_To_Map(std::map<X,Y> & m, X const& key, Y const& val);

template <typename T, typename Y>
void Delete_From_Unordered_Map(std::unordered_map<T,Y> & s, T const& item_to_delete);

template <typename T>
T Follow_Path_Or(std::unordered_map<T,T> const& path, T const& start, int const& amount, T const& or_result);


//overloading on map types
template <typename X, typename Y>
bool Exists_In_Map(std::map<X,Y> const& m, X const& item){
  return m.count(item);
}
template <typename X, typename Y>
bool Exists_In_Unordered_Map(std::unordered_map<X,Y> const& m, X const& item){
  return m.count(item);
}

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




//getting keys /values
template <typename X, typename Y>
std::vector<X> Keys(std::unordered_map<X,Y> const& m){
  std::vector<X> results;
  for (auto const& it: m){
    results.emplace_back(it.first);
  }
  return results;
}
template <typename X, typename Y>
std::vector<X> Keys(std::map<X,Y> const& m){
  std::vector<X> results;
  for (auto const& it: m){
    results.emplace_back(it.first);
  }
  return results;
}
template <typename X, typename Y>
std::vector<X> Keys(std::multimap<X,Y> const& m){
  std::vector<X> results;
  for (auto const& it: m){
    results.emplace_back(it.first);
  }
  return results;
}
template <typename X, typename Y>
std::vector<Y> Values(std::unordered_map<X,Y> const& m){
  std::vector<Y> results;
  for (auto const& it: m){
    results.emplace_back(it.second);
  }
  return results;
}
template <typename X, typename Y>
std::vector<Y> Values(std::map<X,Y> const& m){
  std::vector<Y> results;
  for (auto const& it: m){
    results.emplace_back(it.second);
  }
  return results;
}
template <typename X, typename Y>
std::vector<Y> Values(std::multimap<X,Y> const& m){
  std::vector<Y> results;
  for (auto const& it: m){
    results.emplace_back(it.second);
  }
  return results;
}


//some maps don't allow duplicates
//throw if we've attempted to add a duplicate
template <typename Container, typename First, typename Second, typename Exception>
void Throw_On_Failure_To_Insert_Item(Container & c, First f, Second s, Exception e){
  auto build = std::make_pair(f,s);
  auto result = c.insert(build);
  if (!result.second){
    throw e;
  }
}

template <typename T>
T Get_Value_Add_Zero_If_Missing(std::map<T,T> & m, T const& key){
    if (Exists_In_Map(m,key)){
        return m[key];
    }
    m[key] = "0";
    //std::cout << "out {K: " << key << " V: " << m[key] << "}" << std::endl;
    return m[key];
}

template <typename T, typename U>
T Get_Value_Or_Default(std::map<T,U> const& m, T const& key){
    if (Exists_In_Map(m,key)){
        return m[key];
    }
    
    //not found. return default
    U result;
    return result;
}

template <typename T, typename U>
U Get_Value_Or_Default(std::unordered_map<T,U> m, T const& key){
    if (Exists_In_Unordered_Map(m,key)){
        return m[key];
    }
    
    //not found. return default
    U result;
    return result;
}

template <typename X, typename Y>
void Add_To_Map(std::map<X,Y> & m, X const& key, Y const& val){
  m[key] = val;
  std::cout << "in {K: " << key << " V: " << m[key] << "}" << std::endl;
}

template <typename T, typename Y>
void Delete_From_Unordered_Map(std::unordered_map<T,Y> & s, T const& item_to_delete){
  if (Exists_In_Unordered_Map(s,item_to_delete)){
    s.erase(s.find(item_to_delete));
  }
}

//overloading on map types
template <typename X, typename Y>
std::string To_String(std::map<X,Y> const& m){
  std::string str;
  
  for (auto const& it: m){
    str += std::to_string(it.first) + ": " + std::to_string(it.second) + "\n";
  }
  
  return str;
}

template <typename T>
T Follow_Path_Or(std::unordered_map<T,T> const& path, T const& start, int const& amount, T const& or_result)
{
  T result = start;
  for (int i = 0; i < amount; ++i){
    if (Exists_In_Unordered_Map(path,result)){
      result = path.at(result);
    }
    else{
      return or_result;
    }
  }
  
  return result;
}


template <typename T, typename U>
U Max_Value(std::map<T,U> const& map){
  
  if (map.empty()){
    return 0;
  }
  
  
  U val = map.begin()->second;
  for (auto const& it: map){
    val = std::max(val,it.second);
  }
  return val;
}

template <typename T, typename U>
void Reverse_Value_Numbers(std::map<T,U> & map){
  
  U max = Max_Value(map);
  for (auto & it: map){
    it.second = std::abs(static_cast<long>(it.second - max));
  }
  
}



//adding
template <typename T, typename U>
void Add_If_Larger(std::map<T,U> & map, T const& key, U const& value){
    if (Exists_In_Map(map,key)){
        if (map[key] < value){
            map[key] = value;
        }
    }
    
    //add if missing
    else {
        map.emplace(key,value);
    }
    
}
