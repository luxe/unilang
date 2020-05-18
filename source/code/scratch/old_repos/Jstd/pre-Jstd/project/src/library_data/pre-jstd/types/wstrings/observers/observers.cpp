#include <sstream>
#include <cctype>
#include <map>
#include <utility>
#include <boost/algorithm/string/predicate.hpp>

//observing string functions
bool Space_At_The_Beginning(std::wstring const& s) {

    if (s.empty()) {return false;}
    if (s[0] ==  L' ') {
        return true;
    }

    return false;
 }
bool Space_At_The_End(std::wstring const& s) {

    if (s.empty()) {return false;}
    if (s[s.size()-1] ==  L' ') {
        return true;
    }

    return false;
 }
bool Consecutive_Space_In_The_Middle(std::wstring s) {

    trim(s);
    bool found = false;
    for (auto const& it: s) {
        if (it == L' ') {
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
bool Contains_Capital_Letters(std::wstring const& s) {

    for (auto const& it: s) {
        if (std::isupper(it)) {
            return true;
        }
    }

    return false;
}
bool Contains_Character(std::wstring const& s, char const& c) {

    for (auto const& it: s) {
        if (it == c) {
            return true;
        }
    }
    return false;
}

bool First_Char_Comes_Before_Second_Char(std::wstring const& s, char const& c1, char const& c2) {
    for (auto const& it: s) {
        if (it == c1) {
            return true;
        }else if (it == c2) {
            return false;
        }
    }
    return false;
}

bool Begins_With(std::wstring const& str, std::wstring const& start_part){
    return boost::algorithm::starts_with(str,start_part);
}
bool Ends_With(std::wstring const& str, std::wstring const& end_part){
    return boost::algorithm::ends_with(str,end_part);
}
bool Begins_And_Ends_With(std::wstring const& str, std::wstring const& part){
    return (Begins_With(str,part) && Ends_With(str,part));
}
bool Begins_With(std::wstring const& str, char const& start_part){
    if (!str.empty()){
        return str[0] == start_part;
    }
    return false;
}
bool Ends_With(std::wstring const& str, char const& end_part){
    if (!str.empty()){
        return str.back() == end_part;
    }
    return false;
}
bool Begins_And_Ends_With(std::wstring const& str, char const& part){
    return (Begins_With(str,part) && Ends_With(str,part));
}
bool Contains_Substring(std::wstring const& str, std::wstring const& part){
    if (str.find(part) != std::wstring ::npos){
        return true;
    }
    return false;
}
char First_Char(std::wstring const& str){
    return str[0];
}
char Last_Char(std::wstring const& str){
    return str[str.size()-1];
}
std::wstring Get_File_Extension(std::wstring const& str){
    std::wstring extension;

    for (auto const& it : boost::adaptors::reverse(str)){
        if (it == '.'){
            break;
        }else{
            extension=it+extension;
        }
    }

    return extension;
}

std::vector<size_t> Get_Indexes_Of_Character(std::wstring const& s, char const& c) {
    std::vector<size_t> indexes;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            indexes.push_back(i);
        }
    }

    return indexes;
}
unsigned int Count_Instances_Of_Character(std::wstring const& s, char const& c) {
    unsigned int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            ++count;
        }
    }

    return count;
}

//converting to other types
unsigned int as_unsigned(std::wstring str){
    unsigned int number;
    std::wstringstream ss;
    ss << str;
    ss >> number;

    return number;
}
signed int as_signed(std::wstring str){
    signed int number;
    std::wstringstream ss;
    ss << str;
    ss >> number;

    return number;
}
std::vector<std::wstring> Put_Each_Line_Of_String_Into_A_Vector(std::wstring const& str) {
    std::vector<std::wstring> lines;
    std::wstring temp;

    for (auto const& it: str) {
        if (it == L'\n') {
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
