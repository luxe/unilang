#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
#include <random>
#include <utility>
#include <optional>
#include "code/utilities/types/vectors/transformers/lib.hpp"
#include "code/utilities/data_structures/position/position.hpp"

std::string Get_As_Comma_Seperated_String(std::vector<std::string> strs);
std::string Get_As_Comma_Seperated_Double_Quoted_String(std::vector<std::string> strs);
std::string Get_As_Space_Seperated_String(std::vector<std::string> strs);
std::string Get_As_Newline_Seperated_String(std::vector<std::string> strs);
std::string Table_As_Column_Aligned(std::vector<std::vector<std::string>> table);
size_t Longest_Element_Size(std::vector<std::string> strs);
bool An_Element_Ends_With(std::vector<std::string> const& strs, std::string const& str);


std::vector<std::vector<std::string>> Split_By_Empty_Vector(std::vector<std::string> const& vec);








template <class T>
bool All_Elements_Unique(std::vector<T> &x) {
    std::sort( x.begin(), x.end() ); // O(N log N)
    return std::adjacent_find( x.begin(), x.end() ) == x.end();
}

template <typename T, typename Fun>
void Paiwise_Iterate(std::vector<T> const& v, Fun fun){
  for (size_t i = 1; i < v.size(); ++i){
    fun(v[i-1],v[i]);
  }
}

template <typename T, typename Fun>
void Four_Way_Iterate(std::vector<T> const& v, Fun fun){
  for (size_t i = 3; i < v.size(); ++i){
    fun(v[i-3],v[i-2],v[i-1],v[i]);
  }
}

template <typename T, typename Fun>
void Six_Way_Iterate(std::vector<T> const& v, Fun fun){
  for (size_t i = 5; i < v.size(); ++i){
    fun(v[i-5],v[i-4],v[i-3],v[i-2],v[i-1],v[i]);
  }
}


template <typename T, typename Fun>
void Compare_All_2_Elements(std::vector<T> const& v, Fun fun){
  for (size_t i = 0; i < v.size(); ++i){
    for (size_t j = 0; j < v.size(); ++j){
      if (i != j){
        auto should_return = fun(v[i],v[j]);
        if (should_return){
          return;
        }
      }
    }
  }
}

template <typename T, typename Fun>
void Compare_All_3_Elements(std::vector<T> const& v, Fun fun){
  for (size_t i = 0; i < v.size(); ++i){
    for (size_t j = 0; j < v.size(); ++j){
      for (size_t k = 0; k < v.size(); ++k){
        std::vector<T> temp {static_cast<int>(i),static_cast<int>(j),static_cast<int>(k)};
        if (All_Elements_Unique(temp)){
          auto should_return = fun(v[i],v[j],v[k]);
          if (should_return){
            return;
          }
        }
      }
    }
  }
}


template <typename T>
std::vector<T> Find_2_Elements_That_Sum_To(std::vector<T> const& v, T sum){
  std::vector<T> results;
  Compare_All_2_Elements(v,[&](T x, T y){
      if (x + y == sum){
        results.emplace_back(x);
        results.emplace_back(y);
        return true;
      }
      return false;
  });
  return results;
}

template <typename T>
std::vector<T> Find_3_Elements_That_Sum_To(std::vector<T> const& v, T sum){
  std::vector<T> results;
  Compare_All_3_Elements(v,[&](T x, T y, T z){
      if (x + y + z == sum){
        results.emplace_back(x);
        results.emplace_back(y);
        results.emplace_back(z);
        return true;
      }
      return false;
  });
  return results;
}


template <typename T>
T& Index(std::vector<T> const& t, int i){
  return t[static_cast<size_t>(i)];
}


//Container Based
template <typename T>
size_t Next_Index_In_Round_Robin(T const& t, size_t const& i){
  if (i == t.size()-1){
    return 0;
  }
  return i+1;
}
template <typename T>
size_t Previous_Index_In_Round_Robin(T const& t, size_t const& i){
  if (i == 0){
    return t.size()-1;
  }
  return i-1;
}
template <typename T>
void Set_Next_Index_In_Round_Robin(T const& t, size_t & i){
  i = Next_Index_In_Round_Robin(t,i);
}
template <typename T>
void Set_Previous_Index_In_Round_Robin(T const& t, size_t & i){
  i = Previous_Index_In_Round_Robin(t,i);
}








template <typename T>
size_t Longest_Element_Size_Of_Pair_First(std::vector<std::pair<std::string,T>> const& strs){
  size_t size = 0;
  for (auto const& it: strs){
    if (it.first.size() > size){
      size = it.first.size();
    }
  }
  return size;
}

template <typename T>
size_t Longest_Element_Size_Of_Pair_Second(std::vector<std::pair<T,std::string>> const& strs){
  size_t size = 0;
  for (auto const& it: strs){
    if (it.second.size() > size){
      size = it.second.size();
    }
  }
  return size;
}

template <typename T>
size_t Largest_Element_Size_Of_Pair_First(std::vector<std::pair<int,T>> const& strs){
  size_t val = 0;
  for (auto const& it: strs){
    if (static_cast<size_t>(it.first) > val){
      val = static_cast<size_t>(it.first);
    }
  }
  return val;
}

template <typename T>
size_t Largest_Element_Size_Of_Pair_Second(std::vector<std::pair<T,int>> const& strs){
  size_t val = 0;
  for (auto const& it: strs){
    if (static_cast<size_t>(it.second) > val){
      val = static_cast<size_t>(it.second);
    }
  }
  return val;
}

template <typename T, typename U>
std::vector<std::pair<T,U>> Take_If_First_Pair_Elem_Is_Equal(std::vector<std::pair<T,U>> const& v, T const& elem){
  std::vector<std::pair<T,U>> x;
  for (auto const& it: v){
    if (it.first == elem)
    x.emplace_back(it);
  }
  return x;
}

template <typename T, typename U>
std::vector<T> Take_Firsts_If_Equal(std::vector<std::pair<T,U>> const& v, T const& elem){
  std::vector<T> x;
  for (auto const& it: v){
    if (it.first == elem)
    x.emplace_back(it.first);
  }
  return x;
}
template <typename T, typename U>
std::vector<U> Take_Seconds_If_Equal(std::vector<std::pair<T,U>> const& v, U const& elem){
  std::vector<U> x;
  for (auto const& it: v){
    if (it.second == elem)
    x.emplace_back(it.second);
  }
  return x;
}
template <typename T, typename U>
std::vector<T> Take_Firsts(std::vector<std::pair<T,U>> const& v){
  std::vector<T> x;
  for (auto const& it: v){
    x.emplace_back(it.first);
  }
  return x;
}
template <typename T, typename U>
std::vector<U> Take_Seconds(std::vector<std::pair<T,U>> const& v){
  std::vector<U> x;
  for (auto const& it: v){
    x.emplace_back(it.second);
  }
  return x;
}


template<typename T>
size_t Get_Index_Of_Element(std::vector<T> const& v, T const& element){
    return std::find(v.begin(), v.end(), element) - v.begin();
}

template<typename T>
int Get_Index_Of_Element_If_Exists(std::vector<T> const& v, T const& element){
    auto found = std::find(v.begin(), v.end(), element);
    if (found == std::end(v)){
      return -1;
    }
    return found - v.begin();
}

template<typename T>
bool Safe_Is_Index_Equal(std::vector<T> const& v, int i, T t){
  
  //out of range
  if (i < 0 || static_cast<size_t>(i) >= v.size()){
    return false;
  }
  
  //in range, make check
  return v[static_cast<size_t>(i)] == t;
}

template<typename T>
T Safe_Index_Get(std::vector<T> const& v, int i, T if_missing){
  
  //out of range
  if (i < 0 || static_cast<size_t>(i) >= v.size()){
    return if_missing;
  }
  
  //in range, get
  return v[static_cast<size_t>(i)];
}

template<typename T>
T& Safe_Index_Capped(std::vector<T> & v, int i){
  
  //out of range
  if (i < 0){
    return v[0];
  }
  if (static_cast<size_t>(i) >= v.size()){
    return v[v.size()-1];
  }
  
  //in range, get
  return v[static_cast<size_t>(i)];
}

template<typename T>
size_t Adjust_Index_Capped(std::vector<T> const& v, int i){
  //out of range
  if (i < 0){
    return 0;
  }
  if (static_cast<size_t>(i) >= v.size()){
    return v.size()-1;
  }
  
  //in range, get
  return static_cast<size_t>(i);
}

template<typename T>
T Last_Element(std::vector<T> const& v){
    return v.back();
}
template<typename T>
T& Modifiable_Last_Element(std::vector<T> & v){
    return v.back();
}
template<typename T>
T& Safe_Modifiable_Last_Element(std::vector<T> & v){
    if (v.empty()){
      v.emplace_back(T{});
    }
    return v.back();
}
template<typename T>
T& Add_Modifiable_Last_Element(std::vector<T> & v){
    v.emplace_back(T{});
    return v.back();
}
template<typename T>
T Second_To_Last_Element(std::vector<T> const& v){
    return v[v.size()-2];
}
template<typename T>
T First_Element(std::vector<T> const& v){
    return v.front();
}
template<typename T>
T First_Element_Or(std::vector<T> const& v, T const& val_if_empty){
    if (!v.empty()){
      return v.front();
    }
    return val_if_empty;
}
template<typename T>
T First_Element_Or_Default(std::vector<T> const& v){
    if (!v.empty()){
      return v.front();
    }
    return T{};
}

template <class T>
std::vector<T> Flatten(std::vector<std::vector<T>> const& v){
  std::vector<T> results;
  for (auto const& it: v){
    results.insert(results.end(), it.begin(), it.end());
  }
  
  return results;
}

template<typename T>
T Flatten(std::vector<T> const& v){
	T t;
	for (auto const& it: v){
		t += it;
	}
	return t;
}

std::vector<std::string> Each_Element_As_Space_Seperated_String(std::vector<std::vector<std::string>> const& v);

template<typename T>
bool The_Same_Except_For_One_Element(std::vector<T> const& v1, std::vector<T> const& v2){
	int differences = 0;
	
	if (v1.size() != v2.size()){
		return false;
	}
	
	for (int i = 0; i < v1.size(); ++i){
		if (v1[i].id != v2[i].id){
			differences++;
			if (differences > 1){
				return false;
			}
		}
	}
	
	
	
	if (differences == 1){
		return true;
	}
	return false;
}

template <typename T, typename Fun>
std::vector<T> Filter(std::vector<T> const& vec, Fun pred){
  std::vector<T> new_vec;
  for (auto const& it: vec){
    if (pred(it)){
      new_vec.emplace_back(it);
    }
  }
  
  return new_vec;
}

template <typename T>
std::vector<T> GetPositives(std::vector<T> const& vec){
  return Filter(vec,[](T t){return t > 0;});
}

template <typename T>
std::vector<T> GetNegatives(std::vector<T> const& vec){
  return Filter(vec,[](T t){return t < 0;});
}

template <typename T>
std::vector<T> GetZeros(std::vector<T> const& vec){
  return Filter(vec,[](T t){return t == 0;});
}

template <typename T>
T MaxElement(std::vector<T> vec){
    return *std::max_element(vec.begin(),vec.end());
}

template <typename T>
T MinElement(std::vector<T> vec){
    return *std::min_element(vec.begin(),vec.end());
}



template<typename T>
const T& Get_Nth_Element(std::vector<T> const& container, size_t n) {
  return container[n];
}

template<typename T>
T& Get_Random_Element(std::vector<T> & container) {
	std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(0, container.size() - 1);
	return container[dist(engine)];
}

template <typename T>
bool In_Vector(std::vector<T> const& vec, T const& item){
    return std::find(vec.begin(), vec.end(), item) != vec.end();
}

template <typename T>
bool Vector_Contains_Any_Elements_In_Vector(std::vector<T> const& vec, std::vector<T> const& elements){
    for (auto const& it: elements){
        if (In_Vector(vec,it)){
            return true;
        }
    }
    return false;
}

bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str);
size_t Get_Longest_String_Length_In_Vector(std::vector<std::string> const& v);

template<typename T>
unsigned int Number_Of_Times_Element_Shows_Up_In_Vector(std::vector<T> const& vec, T const& t){
  unsigned int count = 0;
  for (auto it: vec){
    if (it == t){
      ++count;
    }
  }
  return count;
}

template <class T>
bool Contains_All_Unique_Items(const std::vector<T>& vec)
{
    std::set<T> test;
    for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        if (!test.insert(*it).second) {
            return false;
        }
    }
    return true;
}


template<class InputIt, class MemberType>
auto Destructure_Out_Vec_Of_Data_Member(InputIt first, InputIt last, MemberType std::iterator_traits<InputIt>::value_type::* member_name){
  
  //not ideal, but works
  auto i = *first.*member_name;
  std::vector<decltype(i)> v;
  
  while(first != last){
    v.push_back(*first.*member_name);
    ++first;
  }
  
  return v;
}

template<class InputIt, class MemberType, class Value>
auto Get_First_Object_Whose_Data_Member_Matches_Value(InputIt first, InputIt last, MemberType std::iterator_traits<InputIt>::value_type::* member_name, Value const& value){
  
  //not ideal, but works
  auto i = *first.*member_name;
  std::vector<decltype(i)> v;
  
  while(first != last){
    if (*first.*member_name == value){
    	return *first;
    }
    ++first;
  }
  
  return *first;
}

template <typename T>
std::vector<std::vector<T>> Split_Every_N(std::vector<T> const& v, size_t amount){
  std::vector<std::vector<T>> all;
  
  std::vector<T> temp;
  size_t current = 0;
  for (auto const& it: v){
    
    temp.emplace_back(it);
    ++current;
    
    if (current == amount){
      current = 0;
      all.emplace_back(temp);
      temp.clear();
    }
  }
  
  if (!temp.empty()){
    all.emplace_back(temp);
  }
  
  return all;
}

template <typename T>
std::vector<std::vector<T>> Split_Into_N_Parts(std::vector<T> const& v, size_t amount){
  std::vector<std::vector<T>> all;
  
  std::vector<T> temp;
  auto max_amount = (v.size() / amount);
  if (max_amount == 0){
    max_amount = 0;
  }
  
  for (auto const& it: v){
    temp.emplace_back(it);
    if (temp.size() >= max_amount){
      all.emplace_back(temp);
      temp.clear();
    }
  }
  
  if (!temp.empty()){
    all.emplace_back(temp);
  }
  
  return all;
  
}





template <typename T, typename Fun>
bool There_Is_A_Column_Where_Each_Element_Passes_Predicate(std::vector<std::vector<T>> const& grid, Fun fun){
  // auto width = grid[0].size();
  
  // for (size_t i = 0; i < width; ++i){
  //   std::vector<T> collect;
  //   for (auto row: grid){
  //     collect.emplace_back(row[i]);
  //     if (All_Pass_Predicate(collect,fun)){
  //       return true;
  //     }
  //   }
  // }
  
  auto new_grid = transpose(grid);
  return There_Is_A_Row_Where_Each_Element_Passes_Predicate(new_grid,fun);
  
  //return false;
}

template <typename T, typename Fun>
bool There_Is_A_Row_Where_Each_Element_Passes_Predicate(std::vector<std::vector<T>> const& grid, Fun fun){
  
  for (auto row: grid){
      if (All_Pass_Predicate(row,fun)){
        return true;
      }
  }
  
  return false;
}

template <typename T, typename Fun>
bool All_Pass_Predicate(std::vector<T> const& vec, Fun fun){
  
  for (auto v: vec){
    if (!fun(v)){
      return false;
    }
  }
  
  return true;
}



//Counting
template <typename T>
T CountElement(std::vector<T> vec, T element){
    return std::count_if(vec.begin(), vec.end(), [&](T i){return i == element;});
}

template <typename T>
T CountMaxElements(std::vector<T> vec){
    auto max = MaxElement(vec);
    return CountElement(vec,max);
}



//Puzzling
template <typename T>
int minimumAbsoluteDifferenceBetweenAny2Elements(std::vector<T> arr) {
    
    //sort them so we can compare close elements in order
    sort(arr.begin(),arr.end());
    
    //start with worst case
    T min = INT_MAX;
    
    for (size_t i = 0; i < arr.size()-1; ++i){
      
        //track the minimum difference
        min = std::min(abs(arr[i] - arr[i+1]),min);
        
        //you can't beat zero
        if (min == 0){
          return 0;
        }
    }
    return min;

}


template <typename T>
std::vector<std::vector<T>> Get_Paths_In_All_Cardinal_Directions(std::vector<std::vector<T>> vec, Position pos){

  std::vector<std::vector<T>> all_dirs;
  
  
  //get right
  {
    std::vector<T> temp;
    for (size_t i = static_cast<size_t>(pos.x); i < vec[0].size(); ++i){
      temp.emplace_back(vec[pos.y][i]);
    }
    all_dirs.emplace_back(temp);
  }
  
  
  //get left
  {
    std::vector<T> temp;
    for (size_t i = static_cast<size_t>(pos.x+1); i > 0; --i){
      temp.emplace_back(vec[pos.y][i-1]);
    }
    all_dirs.emplace_back(temp);
  }
  
  
  //get up
  {
    std::vector<T> temp;
    for (size_t i = static_cast<size_t>(pos.y+1); i > 0; --i){
      temp.emplace_back(vec[i-1][pos.x]);
    }
    all_dirs.emplace_back(temp);
  }
  
  
  //get down
  {
    std::vector<T> temp;
    for (size_t i = static_cast<size_t>(pos.y); i < vec.size(); ++i){
      temp.emplace_back(vec[i][pos.x]);
    }
    all_dirs.emplace_back(temp);
  }
  
  
  return all_dirs;
}


template <typename T, typename Fun>
void Iterate(std::vector<std::vector<T>> grid, Fun fun){

for (size_t i = 0; i < grid.size(); ++i){
    for (size_t j = 0; j < grid[0].size(); ++j){
        Position pos;
        pos.x = static_cast<int>(j);
        pos.y = static_cast<int>(i);
        fun(pos);
      }
    }
}

template <typename T>
bool First_Element_Higher_Than_All_Others(std::vector<T> v) {
    int first = v[0];
    for (size_t i = 1; i < v.size(); ++i){
        if (v[i] >= first){
            return false;
        }
    }
    return true;
}



template<class InputIt, class MemberType>
auto Split_By_Data_Member_Uniqueness(InputIt first, InputIt last, MemberType std::iterator_traits<InputIt>::value_type::* member_name){

  //would like to no need to instantiate i here
  auto i = *first.*member_name;
  std::vector<std::vector<decltype(i)>> all;
  std::vector<decltype(i)> some;
  
  std::set<decltype(i)> s;
  
  while(first != last){
    if (Exists_In_Set(s,*first.*member_name)){
      all.push_back(some);
      some.clear();
      s.clear();
      
      //then add the one we just found
      some.push_back(*first.*member_name);
      Add_To_Set(s,*first.*member_name);
    }
    else{
      some.push_back(*first.*member_name);
      Add_To_Set(s,*first.*member_name);
    }
    ++first;
  }
  
  if (!some.empty()){
    all.push_back(some);
  }
  
  return all;
}
