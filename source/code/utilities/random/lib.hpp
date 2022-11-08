#pragma once
#include <random>
#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <set>
#include "code/utilities/types/char/optional_letter_case.hpp"


//different ways to get a random bool
bool Random_Bool();
bool Random_Bool_Via_Rand_LSB();
bool Random_Bool_Via_Rand_Mod_2();

//different ways to get a random '1' or '0'
char Zero_Or_One_Via_Rand_LSB();
char Zero_Or_One_Via_Rand_Mod_2();

//different ways to get a random 256 bits
std::string Random_256Bits_Via_Rand_LSB();
std::string Random_256Bits_Via_Rand_Mod_2();

//different ways to extend the bits with further random number generation
void Shift_On_Another_Bit_Via_Rand_LSB(std::string & str);
void Shift_On_Another_Bit_Via_Rand_Mod_2(std::string & str);

//different ways to get a hex character
char Hex_Char_Via_Rand_Mod_16();
char Hex_Char_Via_Gen_Mod_16(std::mt19937 & gen);
char Hex_Char_Via_Gen_Mod_16(std::mt19937_64 & gen);
char Hex_Char_Via_Gen_Mod_16(std::minstd_rand & gen);
char Hex_Char_Via_Gen_Mod_16_PHP();
char Hex_Char_Via_Num(uint64_t num);
char Hex_Char_Via_Num(uint32_t num);

std::string Random_64Char_Hex_Via_Rand();
std::string Random_64Char_Hex_Via_Gen(std::mt19937 & gen);
std::string Random_64Char_Hex_Via_Gen(std::mt19937_64 & gen);
std::string Random_64Char_Hex_Via_Gen(std::minstd_rand & gen);
std::string Random_64Char_Hex_Via_PHP();
std::string Random_64Char_Hex_Via_Nums(std::vector<uint64_t> nums);
std::string Random_64Char_Hex_Via_Nums(std::vector<uint32_t> nums);

void Shift_On_Another_Hex_Via_Rand(std::string & str);
void Shift_On_Another_Hex_Via_Gen(std::string & str, std::mt19937 & gen);
void Shift_On_Another_Hex_Via_Gen(std::string & str, std::mt19937_64 & gen);
void Shift_On_Another_Hex_Via_Gen(std::string & str, std::minstd_rand & gen);
void Shift_On_Another_Hex_Via_PHP(std::string & str);

template <typename Engine>
std::vector<uint32_t> Run_Generator_To_Get_64_Values(Engine & engine){
  std::vector<uint32_t> nums;
  for (size_t i = 0; i < 64; ++i){
    nums.emplace_back(engine());
  }
  return nums;
}


//seeding
void seed_PHP_mt19937(uint32_t i);


//cryptographic random
std::string urandom(size_t amount);


template<typename T>
auto Get_Random_Index(T const& container) -> int {
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
int RandomIntFromRange(T low, T high){
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<T> dist(low, high);
    return dist(engine);
}

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


