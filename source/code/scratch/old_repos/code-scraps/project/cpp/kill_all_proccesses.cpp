/*
logout button is not working.
Solution: kill everything
*/

//STD Libraries
#include <iostream>
#include <cstdlib>

namespace {

}

int main(){

	for (int i{1}; i < 29817; ++i){
		std::cout << i << std::endl;
		system( ("kill -9 " + std::to_string(i)).c_str() );
	}

	return EXIT_SUCCESS;
}

namespace {

}

