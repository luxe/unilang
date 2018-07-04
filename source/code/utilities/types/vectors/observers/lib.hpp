#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
#include <random>

std::string Get_As_Comma_Seperated_String(std::vector<std::string> strs);

template<typename T>
size_t Get_Index_Of_Element(std::vector<T> const& v, T const& element){
    return std::find(v.begin(), v.end(), element) - v.begin();
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
