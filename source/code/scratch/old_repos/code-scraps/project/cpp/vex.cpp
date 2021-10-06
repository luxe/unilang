#include <iostream>
#include <string>

int main(){

// Is this:
// 1) A variable of type std::string initialized to a std::string()?
// 2) The declaration of a function that returns a std::string and has one argument,
//    which is a pointer to a function with no arguments that returns a std::string?
//std::string foo(std::string());

// Is this:
// 1) A variable of type int initialized to int(x)?
// 2) The declaration of a function that returns an int and has one argument,
//    which is an int named x?
//int bar(int(x));

	
// Parentheses resolve the ambiguity
int x = 3;	
std::string foo((std::string()));
int bar((int(x)));

foo.empty();
	
	return EXIT_SUCCESS;
}