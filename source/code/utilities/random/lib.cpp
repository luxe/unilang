#include "code/utilities/random/lib.hpp"
#include "code/utilities/gmp/lib.hpp"


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

std::string Random_Lowercase_Letter(){
	std::vector<std::string> x;
	x.emplace_back("a");
	x.emplace_back("b");
	x.emplace_back("c");
	x.emplace_back("d");
	x.emplace_back("e");
	x.emplace_back("f");
	x.emplace_back("g");
	x.emplace_back("h");
	x.emplace_back("i");
	x.emplace_back("j");
	x.emplace_back("k");
	x.emplace_back("l");
	x.emplace_back("m");
	x.emplace_back("n");
	x.emplace_back("o");
	x.emplace_back("p");
	x.emplace_back("q");
	x.emplace_back("r");
	x.emplace_back("s");
	x.emplace_back("t");
	x.emplace_back("u");
	x.emplace_back("v");
	x.emplace_back("w");
	x.emplace_back("x");
	x.emplace_back("y");
	x.emplace_back("z");
	return Get_Random_Element(x);
}