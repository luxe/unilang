#include "code/utilities/random/lib.hpp"
#include "code/utilities/types/char/lib.hpp"

bool Random_Bool(){
    auto i = RandomIntFromRange(0,1);
    return i;
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