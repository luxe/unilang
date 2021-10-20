//#include "code/utilities/deps/external/php_src/lib.hpp"
#include "code/utilities/random/lib.hpp"
#include "code/utilities/types/char/lib.hpp"

bool Random_Bool(){
    auto i = RandomIntFromRange(0,1);
    return i;
}
bool Random_Bool_Via_Rand_LSB()
{
	return rand() & 1;
}
bool Random_Bool_Via_Rand_Mod_2()
{
	return rand() % 2;
}

char Zero_Or_One_Via_Rand_LSB(){
	return Random_Bool_Via_Rand_LSB() ? '1' : '0';
}
char Zero_Or_One_Via_Rand_Mod_2(){
	return Random_Bool_Via_Rand_Mod_2() ? '1' : '0';
}

std::string Random_256Bits_Via_Rand_LSB(){
	std::string x;
	for (size_t i = 0; i < 256; ++i){
		x += Zero_Or_One_Via_Rand_LSB();
	}
	return x;
}
std::string Random_256Bits_Via_Rand_Mod_2(){
	std::string x;
	for (size_t i = 0; i < 256; ++i){
		x += Zero_Or_One_Via_Rand_Mod_2();
	}
	return x;
}

void Shift_On_Another_Bit_Via_Rand_LSB(std::string & str){
	str.erase(0,1);
	str += Zero_Or_One_Via_Rand_LSB();
}

void Shift_On_Another_Bit_Via_Rand_Mod_2(std::string & str){
	str.erase(0,1);
	str += Zero_Or_One_Via_Rand_Mod_2();
}

char Hex_Char_Via_Rand_Mod_16(){
  return Get_Hex_Char_From_Index(rand()%16);
}
char Hex_Char_Via_Gen_Mod_16(std::mt19937 & gen){
	return Get_Hex_Char_From_Index(gen()%16);
}
char Hex_Char_Via_Gen_Mod_16(std::mt19937_64 & gen){
	return Get_Hex_Char_From_Index(gen()%16);
}
char Hex_Char_Via_Gen_Mod_16(std::minstd_rand & gen){
	return Get_Hex_Char_From_Index(gen()%16);
}
char Hex_Char_Via_Gen_Mod_16_PHP(){
        //the mt_rand impl may be different both in algorithm and architecure (bit size)
	//return Get_Hex_Char_From_Index(php_mt_rand()%16);
	return 0;
}
char Hex_Char_Via_Num(uint64_t num){
	return Get_Hex_Char_From_Index(num%16);
}

std::string Random_64Char_Hex_Via_Rand(){
	std::string x;
	for (size_t i = 0; i < 64; ++i){
		x += Hex_Char_Via_Rand_Mod_16();
	}
	return x;
}
std::string Random_64Char_Hex_Via_Gen(std::mt19937 & gen){
	std::string x;
	for (size_t i = 0; i < 64; ++i){
		x += Hex_Char_Via_Gen_Mod_16(gen);
	}
	return x;
}
std::string Random_64Char_Hex_Via_Gen(std::mt19937_64 & gen){
	std::string x;
	for (size_t i = 0; i < 64; ++i){
		x += Hex_Char_Via_Gen_Mod_16(gen);
	}
	return x;
}
std::string Random_64Char_Hex_Via_Gen(std::minstd_rand & gen){
	std::string x;
	for (size_t i = 0; i < 64; ++i){
		x += Hex_Char_Via_Gen_Mod_16(gen);
	}
	return x;
}
std::string Random_64Char_Hex_Via_PHP(){
	std::string x;
	for (size_t i = 0; i < 64; ++i){
		x += Hex_Char_Via_Gen_Mod_16_PHP();
	}
	return x;
}
std::string Random_64Char_Hex_Via_Nums(std::vector<uint64_t> nums){
	std::string x;
	for (size_t i = 0; i < 64; ++i){
		x += Hex_Char_Via_Num(nums[i]);
	}
	return x;
}
std::string Random_64Char_Hex_Via_Nums(std::vector<uint32_t> nums){
	std::string x;
	for (size_t i = 0; i < 64; ++i){
		x += Hex_Char_Via_Num(nums[i]);
	}
	return x;
}

void Shift_On_Another_Hex_Via_Rand(std::string & str){
	str.erase(0,1);
	str += Hex_Char_Via_Rand_Mod_16();
}
void Shift_On_Another_Hex_Via_Gen(std::string & str, std::mt19937 & gen){
	str.erase(0,1);
	str += Hex_Char_Via_Gen_Mod_16(gen);
}
void Shift_On_Another_Hex_Via_Gen(std::string & str, std::mt19937_64 & gen){
	str.erase(0,1);
	str += Hex_Char_Via_Gen_Mod_16(gen);
}
void Shift_On_Another_Hex_Via_Gen(std::string & str, std::minstd_rand & gen){
	str.erase(0,1);
	str += Hex_Char_Via_Gen_Mod_16(gen);
}
void Shift_On_Another_Hex_Via_PHP(std::string & str){
	str.erase(0,1);
	str += Hex_Char_Via_Gen_Mod_16_PHP();
}

void seed_PHP_mt19937(uint32_t i){
   //php_mt_srand(i);
}


std::string urandom(size_t amount){
    
    // Load private key (seckey) from random bytes
    FILE *frand = fopen("/dev/urandom", "r");
    
    std::string result;
    for (size_t i = 0; i < amount; ++i){
        result += (unsigned char)fgetc(frand);
    }
    
    // Read 32 bytes from frand
    // unsigned char seckey[32];
    // fread(seckey, 32, 1, frand);
    
    // Close the file
    fclose(frand);
    
    //std::string result((char*)seckey);
    return result;
}


std::string Get_Random_By_Probability(std::map<std::string,double> const& m){
	auto num = RandomRealFromRange<double>(0.0,100.0);
	double total = 0;
	for (auto const& it: m){
		if (num <= total+it.second){
			return it.first;
		}
		total += it.second;
	}
	return "?";
}

std::string Random_Letter(Optional_Letter_Case const& c){
	std::string letter;
	
    //get random letter
    if (c == Optional_Letter_Case::UPPER){
        letter = Random_Uppercase_Letter();
    }
    else if (c == Optional_Letter_Case::LOWER){
        letter = Random_Lowercase_Letter();
    }
    else{
        letter = Random_Any_Case_Letter();
    }
    return letter;
}

std::string Random_Lowercase_Letter(){
	auto x = Get_Lowercase_Letters();
	std::string str;
	str += Get_Random_Element(x);
	return str;
}
std::string Random_Uppercase_Letter(){
	auto x = Get_Uppercase_Letters();
	std::string str;
	str += Get_Random_Element(x);
	return str;
}
std::string Random_Any_Case_Letter(){
	auto x = Get_All_Cased_Letters();
	std::string str;
	str += Get_Random_Element(x);
	return str;
}