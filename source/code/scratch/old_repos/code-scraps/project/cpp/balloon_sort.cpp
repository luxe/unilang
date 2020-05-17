#include <vector>
#include <iostream>
#include <algorithm>

int main(){

	std::vector<int> array{4,2,6,4,1,3,0};
	for (size_t i = 0; i < array.size(); ++i){
		for (size_t j = 0; j < array.size()-i; ++j){
			if (array[i] > array[i+j]){
				std::swap(array[i],array[i+j]);
				for (auto it: array){std::cout << it << " ";}std::cout << '\n';
			}
		}
	}

	for (auto it: array){std::cout << it << " ";}std::cout << '\n';
}