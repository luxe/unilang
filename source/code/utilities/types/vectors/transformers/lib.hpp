#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include "code/utilities/types/strings/transformers/casing/lib.hpp"

//whoops.. pre-pre-jstd is really needed
template <typename T>
void Add_To_Set(std::set<T> & s, T const& item_to_add);
template <typename T>
bool Exists_In_Set(std::set<T> const& s, T const& item);
template <typename T>
bool In_Vector(std::vector<T> const& vec, T const& item);




//math (string is treated as integer)
void Add_Each_Line_By(std::vector<std::string> & v, int num);
void Subtract_Each_Line_By(std::vector<std::string> & v, int num);
void Multiply_Each_Line_By(std::vector<std::string> & v, int num);
void Divide_Each_Line_By(std::vector<std::string> & v, int num);
int Accumulate(std::vector<std::string> const& v);



template<typename T>
T& Position_Mode_Index(std::vector<T> & t, size_t index){
  return t[t[index]];
}

template<typename T>
void Position_Mode_Addition(std::vector<T> & t, size_t op1, size_t op2, size_t answer){
    auto a = Position_Mode_Index(t,op1);
    auto b = Position_Mode_Index(t,op2);
    Position_Mode_Index(t,answer) = a+b;
}
template<typename T>
void Position_Mode_Linear_Addition(std::vector<T> & t, size_t & pc){
    auto a = Position_Mode_Index(t,pc+1);
    auto b = Position_Mode_Index(t,pc+2);
    Position_Mode_Index(t,pc+3) = a+b;
    pc += 4;
}

template<typename T>
void Position_Mode_Multiply(std::vector<T> & t, size_t op1, size_t op2, size_t answer){
    auto a = Position_Mode_Index(t,op1);
    auto b = Position_Mode_Index(t,op2);
    Position_Mode_Index(t,answer) = a*b;
}
template<typename T>
void Position_Mode_Linear_Multiply(std::vector<T> & t, size_t & pc){
    auto a = Position_Mode_Index(t,pc+1);
    auto b = Position_Mode_Index(t,pc+2);
    Position_Mode_Index(t,pc+3) = a*b;
    pc += 4;
}




//insert an element between all the elements
template <typename T>
std::vector<T>& intersperse(std::vector<T> & vec, T const& item){
	std::vector<T> new_vec;
	for (size_t i = 0; i < vec.size(); ++i){
		
		new_vec.emplace_back(vec[i]);

		//if its not the last element
		if (i != vec.size()-1){
			new_vec.emplace_back(item);
		}
	}
}





template <typename T>
void Add_To_Back(std::vector<T> & vec, T const& item){
	vec.push_back(item);
}
template <typename T>
void Add_To_Front(std::vector<T> & vec, T const& item){
	vec.insert(vec.begin(), item);
}
template <typename T>
void Add(std::vector<T> & vec, T const& item){
    vec.emplace_back(item);
}
void Add(std::vector<std::string> & vec, std::string const& item);



template <typename T>
void Add_To_Vector_If_Not_Already_There(std::vector<T> & vec, T const& item){
	if (!In_Vector(vec,item)){
		vec.push_back(item);
	}
}

template <typename T>
std::vector<T>& Remove_Element(std::vector<T>& vec, T const& value){
    vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
    return vec;
}

template <typename T>
std::vector<T>& Sort_And_Remove_Duplicates(std::vector<T>& vec){
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

template <typename T>
std::vector<T>& Sort(std::vector<T>& vec){
    std::sort(vec.begin(), vec.end());
    return vec;
}

template <typename T>
std::vector<T> & Sort_For_Colums(std::vector<T>& vec, size_t cols){
    std::vector<T> new_vec;
    
    for (size_t skip_amount = 0; skip_amount < cols+1; ++skip_amount){
        for (size_t i = skip_amount; i < vec.size(); i += cols+1){
            new_vec.emplace_back(vec[i]);
        }
    }
    
    
    vec = new_vec;
    return vec;
}

template <typename T>
std::vector<T>& Remove_Duplicates(std::vector<T>& vec){
    std::vector<T> solution;
    std::set<T> found;
    
    for (auto it: vec){
        if (!Exists_In_Set(found,it)){
            solution.push_back(it);
            Add_To_Set(found,it);
        }
    }
    
    vec = solution;
    return vec;
}

template <typename T>
std::vector<T>& Non_Case_Sensitive_Sort_And_Remove_Duplicates(std::vector<T>& vec){
    std::vector<T> solution;
    std::set<T> found;
    
    for (auto it: vec){
        if (!Exists_In_Set(found,As_Lowercase(it))){
            solution.push_back(it);
            Add_To_Set(found,As_Lowercase(it));
        }
    }
    
    vec = solution;
    std::sort(vec.begin(), vec.end());
    return vec;
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
    vec.erase(vec.begin(), vec.begin() + n);
    return;
}
template <typename T>
void Remove_Last_Element(std::vector<T>& vec){
    vec.pop_back();
    return;
}
template <typename T>
void Remove_Last_N_Elements(std::vector<T>& vec, size_t const& n){
    for (size_t i = 0; i < n; ++i) vec.pop_back();
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
void Remove_Elements_Of_Vector_Two_Found_In_Vector_One(std::vector<T> const& one, std::vector<T> & two){
    for (auto const& it: one){
        auto found = std::find(two.begin(), two.end(), it);
        if (found != two.end()){
            two.erase(found);
        }
    }
}

template <typename T>
std::vector<T>& Lowercase(std::vector<T>& vec){
    std::for_each(vec.begin(),vec.end(),[](T & t){ Lowercase(t); return;});
    return vec;
}
template <typename T>
std::vector<T>& Uppercase(std::vector<T>& vec){
    std::for_each(vec.begin(),vec.end(),[](T & t){ Uppercase(t); return;});
    return vec;
}
template <typename T>
std::vector<T>& Turn_Whitespace_Lines_Into_Empty_Lines(std::vector<T>& vec){
    for (auto & line: vec){
      if (Contains_Only_Whitespace_Characters(line)){
        line.clear();
      }
    }
    return vec;
}

std::vector<std::string>& Remove_First_Elements_That_Are_Whitespace_Elements(std::vector<std::string>& vec);
std::vector<std::string>& Remove_Last_Elements_That_Are_Whitespace_Elements(std::vector<std::string>& vec);
std::vector<std::string>& Remove_Last_Whitespace_Elements_And_Ensure_Only_One_Last_Empty_Element(std::vector<std::string>& vec);
std::vector<std::string>& Remove_Elements_That_Match_String(std::vector<std::string>& vec, std::string const& match);
std::vector<std::string>& Remove_All_Empty_String_Elements(std::vector<std::string>& vec);
std::vector<std::string>& Move_First_Word_Of_String_To_The_End_For_Each_Element(std::vector<std::string>& vec);
std::vector<std::string>& Squeeze_Away_Spaces_For_Each_Element(std::vector<std::string>& vec);
std::vector<std::string>& Squeeze_Whitespace_Elements(std::vector<std::string>& vec);

template <typename T, typename Function>
std::vector<T>& Remove_Elements_Where_Function_Is_True( std::vector<T> & v, Function const& f){
    v.erase( std::remove_if(std::begin(v), std::end(v), f), std::end(v) );
    return v;
}
template <typename T, typename Function>
std::vector<T>& Remove_Elements_Where_Function_Is_False( std::vector<T> & v, Function const& f){
    v.erase( std::remove_if(std::begin(v), std::end(v), !f), std::end(v) );
    return v;
}
template <typename T, typename Function>
std::vector<T>& Remove_If( std::vector<T> & v, Function const& f){
    v.erase( std::remove_if(std::begin(v), std::end(v), f), std::end(v) );
    return v;
}

//void Remove_Empty_Strings(std::vector<std::string> & vec);
//void Remove_Any_Strings_That_Are_Whitespace(std::vector<std::string> & vec);

//this is a joke sort
template <typename value_t>
void BogoSort( std::vector< value_t > & data ){
    while( !std::is_sorted(data.cbegin(), data.cend()) )
    {std::shuffle(data.begin(), data.end());}
}

void Alphabetize_And_Print(std::vector<std::string> results);

template <typename T>
std::vector<std::vector<T>> transpose(const std::vector<std::vector<T>> matrix) {
    // this assumes that all inner vectors have the same size and
    // allocates space for the complete result in advance
    std::vector<std::vector<T>> result(matrix[0].size(),std::vector<T>(matrix.size()));
                                          
                                      
    for (typename std::vector<T>::size_type i = 0; i < matrix[0].size(); ++i){
        for (typename std::vector<T>::size_type j = 0; j < matrix.size(); j++){
            result[i][j] = matrix[j][i];
        }
    }
    
    return result;
}
