#include <gmpxx.h>
#include "code/utilities/gmp/lib.hpp"
#include <sstream>

//gmp function wrapper

//transformers
mpf_class add_all_elements(std::vector<mpf_class> const& nums) {
	mpf_class num("0");
	for (auto const& it: nums) {
		num += it;
	}

	return num;
}
mpz_class add_all_elements(std::vector<mpz_class> const& nums) {
	mpz_class num("0");
	for (auto const& it: nums) {
		num += it;
	}

	return num;
}

mpz_class Factorial(mpz_class n){
  mpz_class answer("1");
  for (mpz_class i = 1; i <= n; ++i){
    answer = answer * i;
  }
  return answer;
}

//observers
std::string to_string(mpz_class const& num){
	std::stringstream ss;
	ss << num;
	return ss.str();
}
mpz_class to_mpz_class(char c){

	switch(c){
		case '1': return mpz_class("1");
		case '2': return mpz_class("2");
		case '3': return mpz_class("3");
		case '4': return mpz_class("4");
		case '5': return mpz_class("5");
		case '6': return mpz_class("6");
		case '7': return mpz_class("7");
		case '8': return mpz_class("8");
		case '9': return mpz_class("9");
	}
	return mpz_class("0");
}
