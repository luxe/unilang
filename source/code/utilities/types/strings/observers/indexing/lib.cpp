#include "code/utilities/types/strings/transformers/casing/lib.hpp"
#include "code/utilities/types/char/lib.hpp"
#include <vector>

std::pair<size_t,size_t> Get_Start_And_End_Positions_Of_First_Word(std::string const& str){
	std::pair<size_t,size_t> p;
	bool word_started = false;
	bool word_ended = false;
	for (size_t i = 0; i < str.size(); ++i){
		if (Is_A_Whitespace_Character(str[i])){
			if (word_started){
				p.second = i;
				word_ended = true;
				break;
			}
		}else{
			if (!word_started){
				p.first = i;	
				word_started = true;
			}	
		}
	}
	
	if (!word_ended){
		p.second = str.size()-1;
	}
	
	return p;
}
std::pair<size_t,size_t> Get_Start_Position_And_Length_Of_First_Word(std::string const& str){
	std::pair<size_t,size_t> p;
	auto points = Get_Start_And_End_Positions_Of_First_Word(str);
	p.first = points.first;
	p.second = points.second - points.first;
	return p;
}

std::vector<size_t> Get_Indexes_Of_Character(std::string const& s, char const& c) {
    std::vector<size_t> indexes;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            indexes.push_back(i);
        }
    }

    return indexes;
}

std::vector<size_t> Get_Indexes_Of_Substring_Through_Case_Insensitive_Comparing(std::string src, std::string substr){
	std::vector<size_t> results;
	auto src_lower = As_Lowercase(src);
	auto substr_lower = As_Lowercase(substr);
	size_t pos = src_lower.find(substr_lower, 0);
	while(pos != std::string::npos)
	{
	    results.push_back(pos);
	    pos = src_lower.find(substr_lower,pos+1);
	}
	
	return results;
}

size_t Get_Index_After_Found_Substring(std::string const& str, std::string const& substring){
	auto found = str.find(substring);
	found += substring.size();
	return found;
}