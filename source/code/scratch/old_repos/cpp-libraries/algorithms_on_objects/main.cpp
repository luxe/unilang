//this program tests the header library

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ostream>
#include "algorithm++.hpp"
#include <algorithm>

template <typename T>
void Test(T func) {
	std::cout << "-------------------------------------------------\n";
	func();
	std::cout << "-------------------------------------------------\n";
	return;
}

void All_Of();

std::string mirror_ends(const std::string& in)
{
    return std::string(in.begin(),
                       mismatch(in, in.rbegin()).first);
}


int main() {

	Test(All_Of);


	return EXIT_SUCCESS;
}

void All_Of() {

    std::vector<int> v{2, 4, 6, 8, 10, 6};

    std::cout << count(v, int(6)) << std::endl;

    auto i = mirror_ends("hello");




	return;
}
