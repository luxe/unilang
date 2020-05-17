#pragma once
#include <vector>
#include <string>
#include <algorithm>

//vector functions
template <typename T> void Sort_And_Remove_Duplicates(std::vector<T>& vec){
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str);
