#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
#include <random>
#include <utility>
#include <optional>

std::string Get_As_Comma_Seperated_String(std::vector<std::string> strs);
std::string Get_As_Space_Seperated_String(std::vector<std::string> strs);
std::string Table_As_Column_Aligned(std::vector<std::vector<std::string>> table);
size_t Longest_Element_Size(std::vector<std::string> strs);



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
  int size = 0;
  for (auto const& it: strs){
    if (it.first.size() > size){
      size = it.first.size();
    }
  }
  return size;
}

template <typename T>
size_t Longest_Element_Size_Of_Pair_Second(std::vector<std::pair<T,std::string>> const& strs){
  int size = 0;
  for (auto const& it: strs){
    if (it.second.size() > size){
      size = it.second.size();
    }
  }
  return size;
}

template <typename T>
size_t Largest_Element_Size_Of_Pair_First(std::vector<std::pair<int,T>> const& strs){
  int val = 0;
  for (auto const& it: strs){
    if (it.first > val){
      val = it.first;
    }
  }
  return val;
}

template <typename T>
size_t Largest_Element_Size_Of_Pair_Second(std::vector<std::pair<T,int>> const& strs){
  int val = 0;
  for (auto const& it: strs){
    if (it.second > val){
      val = it.second;
    }
  }
  return val;
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
bool Safe_Is_Index_Equal(std::vector<T> const& v, size_t i, T t){
  
  //out of range
  if (i < 0 || i >= v.size()){
    return false;
  }
  
  //in range, make check
  return v[i] == t;
}

template<typename T>
T Safe_Index_Get(std::vector<T> const& v, size_t i, T if_missing){
  
  //out of range
  if (i < 0 || i >= v.size()){
    return if_missing;
  }
  
  //in range, get
  return v[i];
}

template<typename T>
T Last_Element(std::vector<T> const& v){
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
T Flatten(std::vector<T> const& v){
	T t;
	for (auto const& it: v){
		t += it;
	}
	return t;
}

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


template<typename T>
const T& Get_Nth_Element(std::vector<T> const& container, size_t n) {
  return container[n];
}

template<typename T>
const T& Get_Random_Element(std::vector<T> const& container) {
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
