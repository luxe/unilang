#include "code/utilities/types/strings/observers/other/lib.hpp"
#include "code/utilities/types/char/lib.hpp"
#include "boost/algorithm/string/predicate.hpp"
#include "boost/algorithm/string.hpp"
#include <sstream>
#include <cctype>
#include <map>
#include <utility>

bool First_Char_Comes_Before_Second_Char(std::string const& s, char const& c1, char const& c2) {
    for (auto const& it: s) {
        if (it == c1) {
            return true;
        }else if (it == c2) {
            return false;
        }
    }
    return false;
}

bool Begins_With(std::string const& str, std::string const& start_part){
    return boost::algorithm::starts_with(str,start_part);
}
bool Ends_With(std::string const& str, std::string const& end_part){
    return boost::algorithm::ends_with(str,end_part);
}
bool Begins_And_Ends_With(std::string const& str, std::string const& part){
    return (Begins_With(str,part) && Ends_With(str,part));
}
bool Begins_Or_Ends_With(std::string const& str, std::string const& part){
	return (Begins_With(str,part) || Ends_With(str,part));
}
bool Begins_With(std::string const& str, char const& start_part){
    if (!str.empty()){
        return str[0] == start_part;
    }
    return false;
}
bool Ends_With(std::string const& str, char const& end_part){
    if (!str.empty()){
        return str.back() == end_part;
    }
    return false;
}
bool Begins_And_Ends_With(std::string const& str, char const& part){
    return (Begins_With(str,part) && Ends_With(str,part));
}
bool Contains_Substring(std::string const& str, std::string const& part){
    if (str.find(part) != std::string ::npos){
        return true;
    }
    return false;
}
bool Contains_Only_Whitespace_Characters(std::string const& str){
  
    for (auto const& it: str){
      if (!isspace(it)){
        return false;
      }
    }
    
    return true;
}

//observing from the front
std::string Get_All_Beginning_Characters_Until_Capital_Letter(std::string const& str){
	std::string new_str;
	
	for (auto const& it: str){
		if (Is_An_Uppercase_Character(it)){
			return new_str;
		}else{
			new_str += it;
		}
	}
	
	return new_str;
}

std::string Get_Substring_Found_Between_First_Instance_Of_Two_Characters(std::string str, char first, char last){
	std::string substring;
	bool found = false;
	for (auto it: str){
		
		if (found){
			if (it == last){break;}
			substring+=it;
		}
		if (it == first){ found = true;}
	}
	return substring;
}
