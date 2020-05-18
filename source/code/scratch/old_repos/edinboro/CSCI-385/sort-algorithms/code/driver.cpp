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
#include "sort_algorithms.hpp" // namespace
#include "algorithm.hpp"       // class
#include "test_suite.hpp"      // namespace

//Function Decelerations
void Validate_Algorithm_Correctness(void);
void Test_Algorithm_Speed(void);
void Output_Title_Of_Table(std::vector<Algorithm<>> const& algorithms);
void Perform_Size_Test(boost::random::mt19937 & gen, int size, std::vector<Algorithm<>> algorithms);
void Output_Results(int i, std::vector<Algorithm<>> const& algorithms);
template <typename IntegerType> void Run_Sort_Performance_Test(Algorithm<IntegerType> & alg, std::vector<Default_Test_Element> vec);

int main(){
	
	//test that the algorithms work
	Validate_Algorithm_Correctness();
	
	//output speed performance data for each algorithm
	//Test_Algorithm_Speed();
	
	return EXIT_SUCCESS;
}

//Function Definitions
void Validate_Algorithm_Correctness(void){
	
	//we generate random numbers of different sized lists and check to see if they are correctly sorted.
	//If there is an issue, the function will report a message through std::cerr
	Test_Suite::Check_Algorithm_Validity ( Sort::Bubble       );
	Test_Suite::Check_Algorithm_Validity ( Sort::Smart_Bubble );
	Test_Suite::Check_Algorithm_Validity ( Sort::Selection    );
	
	return;
}
void Test_Algorithm_Speed(void){
	
	//a vector containing all of the different algorithms we will be testing
	std::vector<Algorithm<>> algorithms;
	algorithms.push_back(Algorithm<>( "Bubble"        ,Sort::Bubble       ));
	algorithms.push_back(Algorithm<>( "Smart Bubble"  ,Sort::Smart_Bubble ));
	algorithms.push_back(Algorithm<>( "Selection"     ,Sort::Selection    ));
	
	
	//build a generator and test the algorithm across a range of bit lengths
	boost::random::mt19937 gen(std::time(0));
	Output_Title_Of_Table(algorithms);
	for (auto list_size = constant::min_number_of_elements; list_size < constant::max_number_of_elements+1; ++list_size){
		Perform_Size_Test(gen,list_size,algorithms);
	}
	
	return;
}

void Output_Title_Of_Table(std::vector<Algorithm<>> const& algorithms){
	
	std::cout << "testing the speed of sort algorithms in milliseconds (" << constant::num_of_trials << " trials for each list length)\n";
	//print out a terrible title just so we know what algorithm is in each column 
	for (auto const& it: algorithms){std::cout << "|" << it.name << "|";}
	std::cout << '\n';
	
	return;
}

void Perform_Size_Test(boost::random::mt19937 & gen, int size, std::vector<Algorithm<>> algorithms){
	
	Default_Test_Element a;
	std::vector<Default_Test_Element> vec;
	auto dist = Test_Suite::Get_Specified_Bit_Length_Distribution(30);
	for (int x = 0; x < constant::num_of_trials; ++x){
		
		//fill up the vector
		for (int i = 0; i < size; ++i){
			a = dist(gen);
			vec.push_back(a);
		}
		
		//test a sort on the vector
		for (auto & it: algorithms){
			Run_Sort_Performance_Test(it,vec);
		}
		vec.clear();
	}
	
	//once data is collected for each algorithm in regards to 
	//specific list lengths, output the results.
	//NOTE: this data will be lost after the function returns.
	//This is because the algorithm classes will be re-used on different list lengths.
	Output_Results(size,algorithms);
	
	return;
}
void Output_Results(int i, std::vector<Algorithm<>> const& algorithms){
	
	//output the total time it took to run the number of trials
	//*You know what, I'm just going to calculate the average in whatever graph software I use
	std::cout << "list-size " << i << ">";
	for (auto it: algorithms){
		std::cout << " " << "(" << (it.total_time) << ")";
	}
	std::cout << '\n';
	
	return;
}
template <typename IntegerType> void Run_Sort_Performance_Test(Algorithm<IntegerType> & alg, std::vector<Default_Test_Element> vec){
	
	boost::posix_time::ptime startTime, endTime;
	
	//time the execution of the algorithm
	startTime = boost::posix_time::microsec_clock::local_time();
	alg.fun(vec);
	endTime = boost::posix_time::microsec_clock::local_time();
	
	alg.total_time += (endTime-startTime);
	++alg.trials;
	
	return;
}

