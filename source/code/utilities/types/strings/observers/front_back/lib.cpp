#include "code/utilities/types/strings/observers/front_back/lib.hpp"
#include "code/utilities/types/char/lib.hpp"

//throws away the space when found
std::string Pop_Off_First_Token(std::string & str){
	std::string token;
	while (!str.empty()){
		if (str[0] == ' '){
			str.erase(0,1);
			return token;
		}
		token += str[0];
		str.erase(0,1);
		
	}
	return token;
}

bool Space_At_The_Beginning(std::string const& s) {

    if (s.empty()) {return false;}
    if (s[0] ==  ' ') {
        return true;
    }

    return false;
 }
bool Space_At_The_End(std::string const& s) {

    if (s.empty()) {return false;}
    if (s[s.size()-1] ==  ' ') {
        return true;
    }

    return false;
 }

char First_Char(std::string const& str){
    return str[0];
}
char Last_Char(std::string const& str){
    return str[str.size()-1];
}