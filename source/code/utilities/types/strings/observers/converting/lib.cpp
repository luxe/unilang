#include "code/utilities/types/strings/observers/converting/lib.hpp"
#include <sstream>

//converting to other types
unsigned int as_unsigned(std::string str){
    unsigned int number;
    std::stringstream ss;
    ss << str;
    ss >> number;

    return number;
}
signed int as_signed(std::string str){
    signed int number;
    std::stringstream ss;
    ss << str;
    ss >> number;

    return number;
}
long as_long(std::string str){
    return std::atol(str.c_str());
}
unsigned long as_unsigned_long(std::string str){
    return std::atol(str.c_str());
}
std::vector<std::string> Put_Each_Line_Of_String_Into_A_Vector(std::string const& str) {
    std::vector<std::string> lines;
    std::string temp;

    for (auto const& it: str) {
        if (it == '\n') {
            lines.push_back(temp);
            temp.clear();
        }else{
            temp += it;
        }
    }

    if (!temp.empty()) {
        lines.push_back(temp);
    }

    return lines;
}

std::vector<std::pair<std::string,std::string>> Put_Each_Line_Of_String_Into_A_Vector_Of_Pairs_Where_The_First_Pair_Elements_Are_Empty(std::string const& str){
	//very ineffecient.  I don't care.  fix later.  pray that the compiler ellides.
	auto single = Put_Each_Line_Of_String_Into_A_Vector(str);
	std::vector<std::pair<std::string,std::string>> dubs;
	for (auto it: single){
		dubs.emplace_back("",it);
	}
	
	return dubs;
}