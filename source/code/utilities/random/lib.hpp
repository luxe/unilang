#pragma once
#include <random>
#include <string>
#include <map>
#include <set>
#include "code/utilities/types/char/optional_letter_case.hpp"


bool Random_Bool();


template<typename T>
auto Get_Random_Index(T const& container) -> std::size_t {
  std::random_device random_device;
  std::mt19937 engine{random_device()};
  std::uniform_int_distribution<int> dist(0, container.size() - 1);
  return dist(engine);
}

template<typename T>
auto Get_Random_Element(T const& container) -> const typename T::value_type&{
	return container[Get_Random_Index(container)];
}


template<typename T>
auto Get_N_Random_Indexes_With_No_Immediate_Duplicates(T const& container, int count) -> std::vector<size_t> {
  std::vector<size_t> indexes;
  
  auto prev_index = Get_Random_Index(container);
  for (size_t i = 0; i < count; ++i){
    
      //keep generating a random until its new
      auto rando = Get_Random_Index(container);
      while (rando == prev_index){
        rando = Get_Random_Index(container);
      }
      
      indexes.emplace_back(rando);
      prev_index = rando;
  }
  
  return indexes;
}

template<typename T>
auto Get_N_Random_Elements_With_No_Immediate_Duplicates(T const& container, int count) -> std::vector<typename T::value_type> {
  T elements;
  auto indexes = Get_N_Random_Indexes_With_No_Immediate_Duplicates(container,count);
  for (auto const& it: indexes){
    elements.emplace_back(container[indexes]);
  }
  return elements;
}


template<typename T>
auto Get_N_Random_Indexes_With_No_Duplicates(T const& container, int count) -> std::vector<size_t> {
  std::vector<size_t> indexes;
  std::set<size_t> seen;
  for (size_t i = 0; i < count; ++i){
    auto rando = Get_Random_Index(container);
    auto found = seen.find(rando);
    while (found != seen.end()){
          rando = Get_Random_Index(container);
          found = seen.find(rando);
    }
    seen.insert(rando);
    indexes.emplace_back(rando);
  }
  return indexes;
}

template<typename T>
auto Get_N_Random_Elements_With_No_Duplicates(T const& container, int count) -> std::vector<typename T::value_type> {
  T elements;
  auto indexes = Get_N_Random_Indexes_With_No_Duplicates(container,count);
  for (auto const& it: indexes){
    elements.emplace_back(container[it]);
  }
  return elements;
}

template <typename T>
T RandomRealFromRange(T low, T high){
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_real_distribution<T> dist(low, high);
    return dist(engine);
}

template <typename T>
T RandomIntFromRange(T low, T high){
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<T> dist(low, high);
    return dist(engine);
}

std::string RandomIntFromRange(std::string low_in, std::string high_in);

template <typename T>
std::string Get_Random_String(T const& password_chars, unsigned int const& length){
  std::string password;
  
  //for loop mentioned in question
  for (unsigned int i = 0; i < length; ++i){
    password += Get_Random_Element(password_chars);
  }
  
  return password;
}

std::string Get_Random_By_Probability(std::map<std::string,double> const& m);


//random letters
std::string Random_Letter(Optional_Letter_Case const& c);
std::string Random_Lowercase_Letter();
std::string Random_Uppercase_Letter();
std::string Random_Any_Case_Letter(); //lowercase or uppercase


