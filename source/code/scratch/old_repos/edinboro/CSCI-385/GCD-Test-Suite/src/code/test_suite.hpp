#pragma once
#include <iostream>
#include <boost/math/common_factor_rt.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <chrono>

#include "globals.hpp"
#include "gcd_algorithms.hpp"

//the Test_Suite namespace contains functions that aid in
//verifying the correctness of gcd algorithms as well as
//testing the performance of generic gcd routines
namespace Test_Suite{
	
	//these functions make sure that the gcd algorithms are correct
	template <typename IntegerType=TestType> bool Check_Algorithm_Validity(IntegerType(*fun)(IntegerType, IntegerType));
	template <typename IntegerType> bool Check_Answer_Validity(IntegerType num1, IntegerType num2, IntegerType answer);
	
	//utility
	template <typename IntegerType=TestType> boost::random::uniform_int_distribution<IntegerType> Get_Specified_Bit_Length_Distribution(int bit_length);
	
};

//these functions make sure that the gcd algorithms are correct
template <typename IntegerType> bool Test_Suite::Check_Algorithm_Validity(IntegerType(*fun)(IntegerType, IntegerType)){
	int fail_rate=0;
	
	IntegerType a;
	IntegerType b;
	
	//test some edge cases
	a=1; b=1;
	fail_rate+= !Check_Answer_Validity(a,b,fun(a,b));
	
	a=1; b=0;
	fail_rate+= !Check_Answer_Validity(a,b,fun(a,b));
	
	a=0; b=1;
	fail_rate+= !Check_Answer_Validity(a,b,fun(a,b));
	
	a=0; b=0;
	fail_rate+= !Check_Answer_Validity(a,b,fun(a,b));
	
	
	//test different sized bit numbers
	static boost::random::mt19937 gen(std::time(0));
	boost::random::uniform_int_distribution<IntegerType> dist;
	for (int i = 0; i < constant::number_of_tests_per_bit_length; ++i){
		
		//6 bit test
		dist = Get_Specified_Bit_Length_Distribution(6);
		a=dist(gen); b=dist(gen);
		fail_rate+= !Check_Answer_Validity(a,b,fun(a,b));
		
		//14 bit test
		dist = Get_Specified_Bit_Length_Distribution(14);
		a=dist(gen); b=dist(gen);
		fail_rate+= !Check_Answer_Validity(a,b,fun(a,b));

		//22 bit test
		dist = Get_Specified_Bit_Length_Distribution(22);
		a=dist(gen); b=dist(gen);
		fail_rate+= !Check_Answer_Validity(a,b,fun(a,b));
		
		//30 bit test
		dist = Get_Specified_Bit_Length_Distribution(30);
		a=dist(gen); b=dist(gen);
		fail_rate+= !Check_Answer_Validity(a,b,fun(a,b));
	}
	
	
	
	bool failed = false;
	if (fail_rate > 0){failed = true;}
	return failed;
}
template <typename IntegerType> bool Test_Suite::Check_Answer_Validity(IntegerType a, IntegerType b, IntegerType d){
	
	//This is mostly bennett's implementation, but I added a bit to check for possible issues
	using namespace std;
	
	//avoid a floating point error
	if (a == 0 && b == 0){
		if (d == 0){
			return true;
		}
		else{
			std::cerr << "gcd(0,0) should be 0" << std::endl;
			return false;
		}
	}
	
	IntegerType r1, r2, d1, d2, p1, p2;
	
	r1 = a%d;
	r2 = b%d;
	d1 = a/d;
	d2 = b/d;
	p1 = d1*d;
	p2 = d2*d;

	if (r1 != 0) {
		cerr<< "Error " << a << "/" << d << " = " << d1 << " R " << r1 << endl;
		cerr << "The remainder should be 0  but is " << r1 << endl;

		return false;
	}

	if (r2 != 0) {
		cerr<< "Error " << b << "/" << d << " = " << d2 << " R " << r2 << endl;
		cerr << "The remainder should be 0  but is " << r2 << endl;

		return false;
	}

	if (p1 != a) {
		cerr << "Error, the proposed GCD is " << d << " but (" 
		<< a << "/" << d << ") * " << d << "  = " <<  p1 << endl;
		cerr << "    and " << p1 << " !=  " << a << endl;
		return false;
	}
	
	if (p2 != b) {
		cerr << "Error, the proposed GCD is " << d << " but (" 
		<< b << "/" << d << ") * " << d << "  = " <<  p2 << endl;
		cerr << "    and " << p2 << " !=  " << b << endl;
		return false;
	}
	
	//I also want to make sure that I'm getting the same answer as boost
	IntegerType boost_answer = boost::math::gcd(a,b);
	if (d != boost_answer){
		cerr << "the answer is " << d << ", but boost got " << boost_answer << endl;
		return false;
	}
	
	return true;
}

//utility
template <typename IntegerType> boost::random::uniform_int_distribution<IntegerType> Test_Suite::Get_Specified_Bit_Length_Distribution(int bit_length){
	IntegerType min = pow(2,bit_length-1);
	IntegerType max = pow(2,bit_length)-1;
	return boost::random::uniform_int_distribution<IntegerType>(min,max);
}




