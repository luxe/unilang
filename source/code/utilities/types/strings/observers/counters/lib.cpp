#include "code/utilities/types/strings/observers/counters/lib.hpp"
#include "code/utilities/types/char/lib.hpp"

unsigned int Starts_With_Char_How_Many_Times(std::string const& str, char c){
	unsigned int count=0;
	
	for (std::size_t i = 0; i < str.size(); ++i){
		if (str[i] == c){
			++count;
		}
		else{
			break;
		}
	}
	
	return count;
}
unsigned int Starts_With_How_Many_Spaces(std::string const& str){
	return Starts_With_Char_How_Many_Times(str,' ');
}
unsigned int Count_Instances_Of_Character(std::string const& s, char const& c) {
    unsigned int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            ++count;
        }
    }

    return count;
}