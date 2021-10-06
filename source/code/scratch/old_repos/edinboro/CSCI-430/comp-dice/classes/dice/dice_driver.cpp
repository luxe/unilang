#include <iostream>
#include <cstdlib>
#include "dice.h"

int main(){
	
	/*
	DiceT dice(0,6);
	
	
	//roll test
	for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); std::cout << dice << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	dice.Roll(); for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	std::cout << "same??" << std::endl;
	for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	for (auto die: dice.Get()){std::cout << die.Value() << " ";} std::cout << '\n';
	
	std::cout << "min" << std::endl;
	std::cout << dice.Min() << std::endl;
	std::cout << "max" << std::endl;
	std::cout << dice.Max() << std::endl;
	std::cout << "sum" << std::endl;
	std::cout << dice.Sum() << std::endl;
	*/
	
	DiceT dice(4,6);
	std::cout << dice << std::endl;
	std::cout << dice.Str() << std::endl;
	std::cout << dice.Str() << std::endl << std::endl;
	
	DiceT dice2(dice.Str());
	std::cout << dice2 << std::endl;
	std::cout << dice2.Str() << std::endl;
	std::cout << dice2.Str() << std::endl << std::endl;
	
	
	
	return EXIT_SUCCESS;
}
