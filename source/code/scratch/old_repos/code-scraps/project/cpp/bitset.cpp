#include <iostream>
#include <bitset>
#include <string>
#include <cstdlib>
#include <stdint.h>


std::bitset<16> operator+(std::bitset<16> const& a, std::bitset<16> const& b){

	//add binary numbers and account for overflow
	std::bitset<16> result("0000000000000000");
	std::bitset<16> m("1");
	for (auto i=0; i < result.size(); ++i){
		std::bitset<16> const diff(((a >> i)&m).to_ullong() + ((b >> i)&m).to_ullong() + (result >> i).to_ullong());
		result ^= (diff ^ (result >> i)) << i;
	}
    return result;
}

int main(){
	
	//Networking
	//std::bitset<16> b1("1000000000000001");//("0100111001100101");
	//std::bitset<16> b2("1000001000000010");//("0111010001110111");
	//std::bitset<16> b3("1000000000000001");//("0110111101110010");
	//std::bitset<16> b4("1000111100000001");//("0110101101101001");
	//std::bitset<16> b5("0000000000000000");//("0110111001100111");
	
	//add the 16-bit numbers and flip-bit the results
	//std::cout << (b1 + b2 + b3 + b4 + b5).flip() << std::endl; //1111001111100001
	
	int32_t num = 20069; //Ne
		    num+= 29815; //tw
			num+= 28530; //or
			num+= 27497; //ki
			num+= 28263; //ng
	
	std::cout << num << std::endl;
	//00000000 00000010 00001100 00011110
	//        2                3102
	//0000110000100000
	

	
	//I got:     0001000100000101 (4357)
	//should be: 0001000100000111 (4359)
	
	//31963
	
	
	
	return 0;
}