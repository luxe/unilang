#include "code/utilities/random/lib.hpp"
#include "code/utilities/math/gmp/lib.hpp"
#include "code/utilities/types/char/lib.hpp"

bool Random_Bool(){
    auto i = RandomIntFromRange(0,1);
    return i;
}


namespace global{
static gmp_randclass gen(gmp_randinit_default);
}

std::string RandomIntFromRange(std::string low_in, std::string high_in){

        //put into large number class
	mpz_class min(low_in);
	mpz_class max(high_in);

	//swap if necessary
	if (min > max) {std::swap(min, max);}

	//build seed
	std::random_device rd;
	global::gen.seed(rd());	

	//generate random number
	mpz_class str = mpz_class(mpz_class(max - min));
	size_t bit_size = mpz_sizeinbase ((str).get_mpz_t(), 2);
	std::string number = to_string(min + ( global::gen.get_z_bits(bit_size) % ( max - min + mpz_class("1") ) ));

	return number;
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