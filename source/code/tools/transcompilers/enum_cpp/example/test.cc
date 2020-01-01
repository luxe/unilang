#include <iostream>
#include <string>
#include "code/transcompilers/enum_cpp/example/test_enum.hpp"

int main(int argc, char** argv){

	Test_Enum e = Test_Enum::FOO;
	std::cout << as_string(e) << std::endl;
}