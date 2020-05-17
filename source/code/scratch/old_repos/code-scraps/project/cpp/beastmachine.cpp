//BEAST MACHINE INTERNATIONAL

#include <iostream>
#include <string>
#include <cstdlib>
#include <random>   //<- boss
#include <unistd.h> //<- gay

int Get_Random_Number(void);


unsigned long GLOBAL_GOOBZ = 10000;
int main(){

	//be a beast machine
    	while ("bitches be hoes"){/////////////////////////////////////////////////
	for (int i = 0; i < 167; ++i){for (int j = i; j >0; --j){std::cout << " ";}
	usleep(GLOBAL_GOOBZ);	std::cout << "BEAST MACHINE" << std::endl;}////////
	for (int i = 167; i > 0; --i){for (int j = i; j >0; --j){std::cout << " ";}
	usleep(GLOBAL_GOOBZ);std::cout << "BEAST MACHINE" << std::endl;}///////////
	}--GLOBAL_GOOBZ; if (GLOBAL_GOOBZ == 0){GLOBAL_GOOBZ = 50000;}}////////////

int Get_Random_Number(void){

	//new random header is boss
	std::string number;
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random_length(1,8);

	int length = random_length(gen);

	return length;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////BEAST MACHINE
