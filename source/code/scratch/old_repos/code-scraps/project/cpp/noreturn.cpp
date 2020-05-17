#include <iostream>
#include <string>
#include <cstdlib>


__attribute__((noreturn)) /*[[noreturn]]*/ void Exit_With_Error(std::string const& error_message);

int main(){
	Exit_With_Error("Error X occurred.");
	return 0;
}

__attribute__((noreturn)) /*[[noreturn]]*/ void Exit_With_Error(std::string const& error_message){
	std::cerr << error_message << std::endl;
	exit(EXIT_FAILURE);
	return;
}