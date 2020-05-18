#pragma once
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>

namespace Sort{
	
	//Sorting algorithms
	
		//Selection Sort
		template <typename IntegerType> std::vector<IntegerType>& Selection(std::vector<IntegerType> & vec);
	
		//Bubble Sorts
		template <typename IntegerType> std::vector<IntegerType>& Bubble(std::vector<IntegerType> & vec);
		template <typename IntegerType> std::vector<IntegerType>& Smart_Bubble(std::vector<IntegerType> & vec);
};


//Selection Sort
template <typename IntegerType> std::vector<IntegerType>& Sort::Selection(std::vector<IntegerType> & vec){
	
	for (int i = 0; i < vec.size(); ++i){
		
		int index_of_min = i;
		for (int j = i; j < vec.size(); ++j){
			if (vec[index_of_min] > vec[j]){
				index_of_min = j;
			}
		}
		std::swap(vec[i],vec[index_of_min]);
	}
	
	return vec;
}
	
//Bubble Sorts
template <typename IntegerType> std::vector<IntegerType>& Sort::Bubble(std::vector<IntegerType> & vec){
	
	for (int i = 0; i < vec.size(); ++i){
		for (int j = 0; j < vec.size()-1; ++j){
			if (vec[j] > vec[j+1]){
				std::swap(vec[j],vec[j+1]);
			}
		}
	}
	
	return vec;
}
template <typename IntegerType> std::vector<IntegerType>& Sort::Smart_Bubble(std::vector<IntegerType> & vec){
	
	bool done = false;
	int size = vec.size();
	while (!done){
		done = true;
		for (int i = 0; i < size-1; ++i){
			if (vec[i] > vec[i+1]){
				done = false;
				std::swap(vec[i],vec[i+1]);
			}
		}
		--size;
	}
	
	return vec;
}
