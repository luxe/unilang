//BEAST MACHINE INTERNATIONAL

#include <iostream>
#include <string>
#include <cstdlib> 
#include <random>
#include <unistd.h>

int Get_Random_Number(void);

int main(){
    while ("bitches be hoes"){
		for (int i = 0; i < 50; ++i){for (int j = i; j >0; --j){std::cout << " ";}
		std::cout << "BEAST MACHINE" << std::endl;}/******* NICE CODE BRO *******/
		for (int i = 50; i > 0; --i){for (int j = i; j >0; --j){std::cout << " ";}
		usleep(1000);std::cout << "BEAST MACHINE" << std::endl;}
	}}

int Get_Random_Number(void){
	
	std::string number;
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random_length(1,8);
	
	int length = random_length(gen); 
	
	return length;
}
