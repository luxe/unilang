#pragma once
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
void Sort_And_Remove_Duplicates(std::vector<T>& vec){
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    return;
}
template <typename T>
std::vector<T>& Reverse_Each_String(std::vector<T>& vec){
    for (auto & it: vec){
        Reverse(it);
    }
    return vec;
}
template <typename T>
void Remove_First_Element(std::vector<T>& vec){
    vec.erase(vec.begin());
    return;
}
template <typename T>
void Remove_First_N_Elements(std::vector<T>& vec, size_t const& n){
    vec.erase(vec.begin(), vec.begin() + n + 1);
    return;
}
template <typename T>
void Remove_Last_Element(std::vector<T>& vec){
    vec.pop_back();
    return;
}
template <typename T>
void Remove_Last_N_Elements(std::vector<T>& vec, size_t const& n){
    for (int i = 0; i < n; ++i) vec.pop_back();
    return;
}
template <typename T>
void Remove_Nth_Element(std::vector<T>& vec, size_t const& n){
    vec.erase(vec.begin() + n);
    return;
}

template <typename T>
void Remove_Element_Range(std::vector<T>& vec, size_t const& start, size_t const& end){
    vec.erase(vec.begin() + start, vec.begin() + end + 1);
    return;
}

template <typename T>
void Remove_Elements_Of_Vector_One_Found_In_Vector_Two(std::vector<T> & one, std::vector<T> const& two){
    for (auto const& it: two){
        auto found = std::find(one.begin(), one.end(), it);
        if (found != one.end()){
            one.erase(found);
        }
    }
}

template <typename T>
void Lowercase(std::vector<T>& vec){
    std::for_each(vec.begin(),vec.end(),[](T & t){ Lowercase(t); return;});
}
template <typename T>
void Uppercase(std::vector<T>& vec){
    std::for_each(vec.begin(),vec.end(),[](T & t){ Uppercase(t); return;});
}
template <typename T>
void Turn_Whitespace_Lines_Into_Empty_Lines(std::vector<T>& vec){
    for (auto & line: vec){
      if (Contains_Only_Whitespace_Characters(line)){
        line.clear();
      }
    }
}

//void Remove_Empty_Strings(std::vector<std::string> & vec);
//void Remove_Any_Strings_That_Are_Whitespace(std::vector<std::string> & vec);

//this is a joke sort
template <typename value_t>
void BogoSort( std::vector< value_t > & data ){
    while( !std::is_sorted(data.cbegin(), data.cend()) )
    {std::shuffle(data.begin(), data.end());}
}
