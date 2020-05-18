#pragma once
#include <iostream>
#include <boost/math/common_factor_rt.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <chrono>
#include <vector>

#include "globals.hpp"

//the Test_Suite namespace contains functions that aid in
//verifying the correctness of gcd algorithms as well as
//testing the performance of generic gcd routines
namespace Test_Suite{
	
	//these functions make sure that the gcd algorithms are correct
	template <typename IntegerType=Default_Test_Element> bool Check_Algorithm_Validity(std::vector<IntegerType>&(*fun_)(std::vector<IntegerType>&));
	template <typename IntegerType=Default_Test_Element> bool Check_Answer_Validity(std::vector<Default_Test_Element> const& vec);
	
	//utility
	template <typename IntegerType=Default_Test_Element> boost::random::uniform_int_distribution<IntegerType> Get_Specified_Bit_Length_Distribution(int bit_length);
	
};

//these functions make sure that the gcd algorithms are correct
template <typename IntegerType> bool Test_Suite::Check_Algorithm_Validity(std::vector<IntegerType>&(*fun_)(std::vector<IntegerType>&)){
	int fail_rate=0;
	
	boost::random::mt19937 gen(std::time(0));
	Default_Test_Element a;
	std::vector<Default_Test_Element> vec;
	auto dist = Test_Suite::Get_Specified_Bit_Length_Distribution(30);
	
	//fill up the vector
	for (int i = 0; i < 100; ++i){
		a = dist(gen);
		vec.push_back(a);
	}
	
	//std::cout << "no: "; for (auto it: vec){std::cout << it << ",";}std::cout << std::endl << std::endl;
	
	fun_(vec);
	fail_rate += Test_Suite::Check_Answer_Validity(vec);
	
	bool failed = false;
	if (fail_rate > 0){failed = true;}
	return failed;
}
template <typename IntegerType> bool Test_Suite::Check_Answer_Validity(std::vector<Default_Test_Element> const& vec){
	
	Default_Test_Element min = 0;
	if (!vec.empty()){
		min = vec[0];
	}
	
	for (auto const& it: vec){
		if (min > it){
			std::cerr << "list not sorted." << std::endl;
			return false;
		}
	}
	
	//std::cout << "yes: "; for (auto it: vec){std::cout << it << ",";}std::cout << std::endl << std::endl;
	
	return true;
}

//utility
template <typename IntegerType> boost::random::uniform_int_distribution<IntegerType> Test_Suite::Get_Specified_Bit_Length_Distribution(int bit_length){
	IntegerType min = pow(2,bit_length-1);
	IntegerType max = pow(2,bit_length)-1;
	return boost::random::uniform_int_distribution<IntegerType>(min,max);
}

















