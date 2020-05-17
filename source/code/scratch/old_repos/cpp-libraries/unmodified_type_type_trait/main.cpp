#include <iostream>
#include <string>
#include "unmodified_type.hpp"

int main(){

	std::cout << std::boolalpha;

	std::cout << std::is_same<base_type<int&>, int>::value << '\n';
	std::cout << std::is_same<base_type<int>, int>::value << '\n';
	std::cout << std::is_same<base_type<int&&>, int>::value << '\n';
}
