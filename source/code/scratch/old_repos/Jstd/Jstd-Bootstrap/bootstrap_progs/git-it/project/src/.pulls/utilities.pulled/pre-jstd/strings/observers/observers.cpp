#include <sstream>
#include <cctype>
#include <map>
#include <utility>
#include <boost/algorithm/string/predicate.hpp>

//apply character testing on all elements of string
bool Is_Only_Control_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Control_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Printable_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Printable_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Whitespace_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Whitespace_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Blank_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Blank_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Graphical_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Graphical_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Puncuation_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Puncuation_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Alphanumberic_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Alphanumberic_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Alpha_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Alpha_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Uppercase_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Uppercase_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Lowercase_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Lowercase_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Numeric_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Numeric_Character(it)){return false;}
    }
    return true;
}
bool Is_Only_Hexidecimal_Characters(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Hexidecimal_Character(it)){return false;}
    }
    return true;
}
bool Has_Only_Lowercase_Letters_And_Underscores(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Lowercase_Character(it) && it != '_'){return false;}
    }
    return true;
}
bool Has_Only_Uppercase_Letters_And_Underscores(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Uppercase_Character(it) && it != '_'){return false;}
    }
    return true;
}

//observing string functions
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
bool Consecutive_Space_In_The_Middle(std::string s) {

    trim(s);
    bool found = false;
    for (auto const& it: s) {
        if (it == ' ') {
            if (found) {
                return true;
            }
            found = true;
        }
        else{
            found = false;
        }
    }
    return false;
}
bool Contains_Capital_Letters(std::string const& s) {

    for (auto const& it: s) {
        if (std::isupper(it)) {
            return true;
        }
    }

    return false;
}
bool Contains_Character(std::string const& s, char const& c) {

    for (auto const& it: s) {
        if (it == c) {
            return true;
        }
    }
    return false;
}

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
char First_Char(std::string const& str){
    return str[0];
}
char Last_Char(std::string const& str){
    return str[str.size()-1];
}

std::pair<std::string,std::string> Split_By_Char(std::string const& str, char const& c){
    std::pair<std::string,std::string> p;
    bool left = true;
    for (auto const& it: str){
    
        if (left){
            if (it == c){left = false;}
            else{p.first+=it;}
        }
        else{p.second+=it;}
        
    }    
    return p;
}

std::string Get_File_Extension(std::string const& str){
    std::string extension;

    for (auto const& it : boost::adaptors::reverse(str)){
        if (it == '.'){
            break;
        }else{
            extension=it+extension;
        }
    }

    return extension;
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
unsigned int Count_Instances_Of_Character(std::string const& s, char const& c) {
    unsigned int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            ++count;
        }
    }

    return count;
}

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
