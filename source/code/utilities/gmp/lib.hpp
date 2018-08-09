#pragma once
#include <vector>
#include <string>
#include <gmpxx.h>

//gmp functions

//transformers
mpf_class add_all_elements(std::vector<mpf_class> const& nums);
mpz_class add_all_elements(std::vector<mpz_class> const& nums);

mpz_class Factorial(mpz_class n);

//observers
std::string to_string(mpz_class const& num);
mpz_class to_mpz_class(char c);
