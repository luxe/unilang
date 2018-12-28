#include "code/utilities/random/lib.hpp"
#include "code/utilities/gmp/lib.hpp"
#include <gmpxx.h>


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
