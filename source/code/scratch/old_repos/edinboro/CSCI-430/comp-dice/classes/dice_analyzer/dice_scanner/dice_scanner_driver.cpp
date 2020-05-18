/*

*/

//STD Libraries
#include <iostream>
#include <cstdlib>
#include "dice_scanner.h"
#include "../dice_tokens/dice_tokens.h"


int main(){

	Dice_ScannerT dice_scanner;
	dice_scanner.Analyze();
	std::cout << int(dice_scanner.Token()) << "|" << dice_scanner.Value() << std::endl;
	while (6 != int(dice_scanner.Token())){
		
		dice_scanner.Analyze();
		std::cout << int(dice_scanner.Token()) << "|" << dice_scanner.Value() << std::endl;
	}



	return EXIT_SUCCESS;
}


