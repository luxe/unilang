#include "day3_2017.hpp"






 int Day3_2017::Steps_To_Corner(int number){

	int base1 = 3;
	int base2 = 1;
	int total = 1;

	int layer_count = 1;

int diff = 1;
int low_amount = 1;


	while (true){

		total += base1*2 + base2*2;
		base1 += 2;
		base2 += 2;



		low_amount += diff;
		diff+=8;


		std::cout << low_amount << "|" << total << " | " << layer_count << "(" << base1 << "x" << base2 << ")" << std::endl;

		
		layer_count++;
		if (total >= number){


			std::cout << "sdf: " << total-number << '\n';
			return (layer_count*2)-1;
		}
	}
}



 void Day3_2017::Go(){

	std::cout << "hello world" << std::endl;


std::cout << Steps_To_Corner(368078) << '\n';
}