#include <iostream>
#include <cstdlib>

#include "die.h"

int main(){
	
	/*
	DieT die(1,6);
	
	die.Roll();std::cout << die << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	die.Roll();std::cout << die.Value() << " ";
	
	std::cout << std::endl << "same??" << std::endl;
	std::cout << die.Value() << " ";
	std::cout << die.Value() << " ";
	std::cout << die.Value() << " ";
	std::cout << die.Value() << " ";
	std::cout << die.Value() << " ";
	std::cout << die.Value() << " ";
	std::cout << die.Value() << " ";
	std::cout << die.Value() << " \n";
	*/
	
	DieT die(1,6,5);
	std::cout << die << std::endl;
	die.Roll();
	std::cout << die << std::endl;
	
	
	return EXIT_SUCCESS;
}
