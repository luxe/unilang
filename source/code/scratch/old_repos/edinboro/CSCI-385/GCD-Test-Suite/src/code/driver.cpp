//Trevor Hickey
//Homework 1: GCD
//Sept. 11

//STD
#include <iostream>
#include <string>
#include <cmath>
#include <functional>

//Boost
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

//My Sources
#include "globals.hpp"         // types & constants
#include "gcd_algorithms.hpp"  // namespace
#include "algorithm.hpp"       // class
#include "test_suite.hpp"      // namespace

//Function Decelerations
void Validate_Algorithm_Correctness(void);
void Test_Algorithm_Speed(void);
void Output_Title_Of_Table(std::vector<Algorithm<>> const& algorithms);
void Perform_Bit_Test(boost::random::mt19937 & gen, int i, std::vector<Algorithm<>> algorithms);
void Output_Results(int i, std::vector<Algorithm<>> const& algorithms);
template <typename IntegerType> void Run_GCD_Performance_Test(Algorithm<IntegerType> & alg, IntegerType a, IntegerType b);

int main(){

	//test that the algorithms work
	Validate_Algorithm_Correctness();

	//output speed performance data for each algorithm
	Test_Algorithm_Speed();

	return EXIT_SUCCESS;
}

//Function Definitions
void Validate_Algorithm_Correctness(void){

	//we generate some random numbers of different bit lengths and check edge cases to
	//make sure that the algorithms all produce the desired results.
	//If there is an issue, the function will report a message through std::cerr
	Test_Suite::Check_Algorithm_Validity ( GCD::Euclid_Recursive    );
	Test_Suite::Check_Algorithm_Validity ( GCD::Euclid_Iterative    );
	Test_Suite::Check_Algorithm_Validity ( GCD::Euclid_Unrolled     );
	Test_Suite::Check_Algorithm_Validity ( GCD::Euclid_Bit          );
	Test_Suite::Check_Algorithm_Validity ( GCD::Binary_Recursive    );
	Test_Suite::Check_Algorithm_Validity ( GCD::Binary_Iterative    );
	Test_Suite::Check_Algorithm_Validity ( GCD::Binary_Iterative_V2 );
	Test_Suite::Check_Algorithm_Validity ( GCD::CTZ                 );
	Test_Suite::Check_Algorithm_Validity ( GCD::Boost               );

	//I'm leaving these algorithms out, because they are slow
	//Test_Suite::Check_Algorithm_Validity (GCD::Brute_Force);
	//Test_Suite::Check_Algorithm_Validity (GCD::Factor);

	return;
}
void Test_Algorithm_Speed(void){

	//a vector containing all of the different algorithms we will be testing
	std::vector<Algorithm<>> algorithms;
	algorithms.push_back(Algorithm<>( "Euclid_Recursive"    ,GCD::Euclid_Recursive    ));
	algorithms.push_back(Algorithm<>( "Euclid_Iterative"    ,GCD::Euclid_Iterative    ));
	algorithms.push_back(Algorithm<>( "Euclid_Unrolled"     ,GCD::Euclid_Unrolled     ));
	algorithms.push_back(Algorithm<>( "Euclid_Bit"          ,GCD::Euclid_Bit          ));
	algorithms.push_back(Algorithm<>( "Binary_Recursive"    ,GCD::Binary_Recursive    ));
	algorithms.push_back(Algorithm<>( "Binary_Iterative"    ,GCD::Binary_Iterative    ));
	algorithms.push_back(Algorithm<>( "Binary_Iterative_V2" ,GCD::Binary_Iterative_V2 ));
	algorithms.push_back(Algorithm<>( "CTZ"                 ,GCD::CTZ                 ));
	algorithms.push_back(Algorithm<>( "Boost"               ,GCD::Boost               ));


	//build a generator and test the algorithm across a range of bit lengths
	boost::random::mt19937 gen(std::time(0));
	Output_Title_Of_Table(algorithms);
	for (auto i = constant::min_bit_length; i < constant::max_bit_length; ++i){
		Perform_Bit_Test(gen,i,algorithms);
	}

	return;
}
void Output_Title_Of_Table(std::vector<Algorithm<>> const& algorithms){

	std::cout << "testing the speed of GCD algorithms in milliseconds (" << constant::num_of_trials << " trials for each bit length)\n";
	//print out a terrible title just so we know what algorithm is in each column
	for (auto const& it: algorithms){std::cout << "|" << it.name << "|";}
	std::cout << '\n';
	
	return;
}
void Perform_Bit_Test(boost::random::mt19937 & gen, int i, std::vector<Algorithm<>> algorithms){

	//loop through each algorithm and test its speed against random numbers of a particular bit length
	TestType a,b;
	auto dist = Test_Suite::Get_Specified_Bit_Length_Distribution(i);
	for (int i = 0; i < constant::num_of_trials; ++i){
		a = dist(gen);
		b = dist(gen);
		for (auto & it: algorithms){
			Run_GCD_Performance_Test(it,a,b);
		}
	}

	//once data is collected for each algorithm in regards to
	//specific bit length numbers, output the results.
	//NOTE: this data will be lost after the function returns.
	//This is because the algorithm classes will be re-used on different bit lengths.
	Output_Results(i,algorithms);

	return;
}
void Output_Results(int i, std::vector<Algorithm<>> const& algorithms){

	//output the total time it took to run the number of trials
	//*You know what, I'm just going to calculate the average in whatever graph software I use
	std::cout << "bit-length " << i << ">";
	for (auto it: algorithms){
		std::cout << " " << "(" << (it.total_time) << ")";
	}
	std::cout << '\n';

	return;
}
template <typename IntegerType> void Run_GCD_Performance_Test(Algorithm<IntegerType> & alg, IntegerType a, IntegerType b){

	boost::posix_time::ptime startTime, endTime;

	//time the execution of the algorithm
	startTime = boost::posix_time::microsec_clock::local_time();
	alg.fun(a,b);
	endTime = boost::posix_time::microsec_clock::local_time();

	alg.total_time += (endTime-startTime);
	++alg.trials;

	return;
}

