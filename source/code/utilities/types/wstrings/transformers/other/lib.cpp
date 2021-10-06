#include "code/utilities/types/wstrings/transformers/other/lib.hpp"
#include "code/utilities/types/wstrings/transformers/trimming/lib.hpp"
#include "code/utilities/types/char/lib.hpp"
#include <sstream>
#include <cctype>
#include <map>
#include <utility>
#include <string>
#include "boost/algorithm/string/predicate.hpp"
#include "boost/range/adaptor/reversed.hpp"

//transforming string functions

std::wstring& Squeeze_Away_Spaces(std::wstring &s){
    std::wstring::iterator new_end = std::unique(s.begin(), s.end(), [](char lhs, char rhs) { return (lhs == rhs) && (lhs == L' '); });
    s.erase(new_end, s.end());
    return s;
}


//changing front and back
std::wstring& Remove_First_Char(std::wstring &s){
    if (!s.empty()){
        s.erase(0,1);
    }
    return s;
}
std::wstring& Remove_Last_Char(std::wstring &s){
    if (!s.empty()){
        s.pop_back();
    }
    return s;
}
std::wstring As_First_Char_Removed(std::wstring const& s){
    std::wstring new_string = s;
    return Remove_First_Char(new_string);
}
std::wstring As_Last_Char_Removed(std::wstring const& s){
    std::wstring new_string = s;
    return Remove_Last_Char(new_string);
}

std::wstring& Remove_All_Chars_From_Front_Until_Char_Is_Seen(std::wstring & str, char const& c){
    while(1){
        if (str.empty()){
            break;
        }else{
            if(str[0] == c){
                break;
            }else{
                str.erase(0,1);
            }
        }
    }
    return str;
}
std::wstring& Remove_All_Chars_From_Back_Until_Char_Is_Seen(std::wstring & str, char const& c){
    while(1){
        if (str.empty()){
            break;
        }else{
            if(Last_Char(str) == c){
                break;
            }else{
                Remove_Last_Char(str);
            }
        }
    }
    return str;
}

std::wstring& Remove_All_Chars_From_Front_Until_Char_Is_Seen_A_Number_Of_Times(std::wstring & str, char const& c, unsigned int number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        Remove_All_Chars_From_Front_Until_Char_Is_Seen(str,c);
        if (i < number_of_times-1){
            Remove_First_Char(str);
        }
    }
    return str;
}
std::wstring& Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(std::wstring & str, char const& c, unsigned int number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        Remove_All_Chars_From_Back_Until_Char_Is_Seen(str,c);
        if (i < number_of_times-1){
            Remove_Last_Char(str);
        }
    }
    return str;
}

std::wstring& Remove_First_N_Chars(std::wstring & str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.erase(0,1);
        }else{
            return str;
        }
    }
    return str;
}
std::wstring& Remove_Last_N_Chars(std::wstring & str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.pop_back();
        }else{
            return str;
        }
    }
    return str;
}

std::wstring As_First_N_Chars_Removed(std::wstring str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.erase(0,1);
        }else{
            return str;
        }
    }
    return str;
}
std::wstring As_Last_N_Chars_Removed(std::wstring str, unsigned int const& number_of_times){
    for (unsigned int i = 0; i < number_of_times; ++i){
        if (!str.empty()){
            str.pop_back();
        }else{
            return str;
        }
    }
    return str;
}

std::wstring& Remove_N_Chars_From_Front_And_Back(std::wstring & str, unsigned int const& number_of_times){
    return Remove_First_N_Chars(Remove_Last_N_Chars(str,number_of_times),number_of_times);
}
std::wstring As_N_Chars_Removed_From_Front_And_Back(std::wstring str, unsigned int const& number_of_times){
    return As_First_N_Chars_Removed(As_Last_N_Chars_Removed(str,number_of_times),number_of_times);
}

std::wstring& Remove_Suffix(std::wstring &s) {
    auto it = s.rfind(L".");
    if (it !=  std::wstring::npos) {
        s.erase(it, s.size());
    }
    return s;
}
std::wstring As_Removed_Suffix(std::wstring s) {
    auto it = s.rfind(L".");
    if (it !=  std::wstring::npos) {
        s.erase(it, s.size());
    }
    return s;
}

std::wstring& Add_File_Extension(std::wstring &s, std::wstring const& extension){
    s+=L"." + extension;
    return s;
}
std::wstring As_Added_File_Extension(std::wstring s, std::wstring const& extension){
    return s+L"." + extension;
}

std::wstring& Replace_File_Extension(std::wstring &s, std::wstring const& new_extension){
    Add_File_Extension(Remove_Suffix(s),new_extension);
    return s;
}
std::wstring As_Replaced_Extension(std::wstring s, std::wstring const& new_extension){
    return As_Added_File_Extension(As_Removed_Suffix(s),new_extension);
}

//changing the end of a string (assuming it's a directory name)
std::wstring Get_Path_As_A_Number_Of_Directories_Back(std::wstring dir_name, unsigned int const& amount_back){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',amount_back);
    return dir_name;
}
std::wstring Get_Path_As_One_Directories_Back(std::wstring dir_name){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',1);
    return dir_name;
}
std::wstring Get_Path_As_Two_Directories_Back(std::wstring dir_name){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',2);
    return dir_name;
}
std::wstring Get_Path_As_Three_Directories_Back(std::wstring dir_name){
    Remove_All_Chars_From_Back_Until_Char_Is_Seen_A_Number_Of_Times(dir_name,'/',3);
    return dir_name;
}

//casing
std::wstring& Uppercase(std::wstring &str){
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
std::wstring& Lowercase(std::wstring &str){
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
std::wstring As_Uppercase(std::wstring str){
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
std::wstring As_Lowercase(std::wstring str){
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
std::wstring Make_Capital_And_Underscored_In_User_Type_Format(std::wstring s) {

    trim(s);
    Squeeze_Away_Spaces(s);

    //turn spaces into underscores and capitalize each letter
    bool was_space = true; // <- capitalize the first character every time
    for (auto & it: s){
        if (it == L' ' || it == L'_'){
            it =L'_';
            was_space = true;
        }else{
            if (was_space){
                it = static_cast<char>(toupper(it));
                was_space = false;
            }
        }
    }

    return s;
}
std::wstring As_All_Capital_Letters_With_Spaces_As_Underscores(std::wstring s) {

    trim(s);
    Squeeze_Away_Spaces(s);
    for (auto & it: s){
        if (it == L' '){ it =L'_'; }
        else { it = static_cast<char>(toupper(it)); }
    }

    return s;
}
std::wstring As_All_Lowercase_Letters_With_Spaces_As_Underscores(std::wstring s){
    trim(s);
    Squeeze_Away_Spaces(s);
    for (auto & it: s){
        if (it == L' '){ it =L'_'; }
        else { it = static_cast<char>(tolower(it)); }
    }

    return s;
}

std::wstring string_replace_first_instance( std::wstring src, std::wstring const& target, std::wstring const& repl){
    // handle error situations/trivial cases

    if (target.length() == 0 || src.length() == 0) {
        return src;
    }

    size_t idx = 0;

        idx = src.find( target, idx);

        src.replace( idx, target.length(), repl);
        idx += repl.length();

    return src;
}
std::wstring string_replace_all( std::wstring src, std::wstring const& target, std::wstring const& repl){

    if (target.length() == 0) {
        // searching for a match to the empty string will result in
        //  an infinite loop
        //  it might make sense to throw an exception for this case
        return src;
    }

    if (src.length() == 0) {
        return src;  // nothing to match against
    }

    size_t idx = 0;

    for (;;) {
        idx = src.find( target, idx);
        if (idx == std::wstring::npos)  break;

        src.replace( idx, target.length(), repl);
        idx += repl.length();
    }

    return src;
}

std::wstring& replace_all( std::wstring & src, char const& c1, char const& c2) {
    for (auto & it: src) {
        if (it ==  c1) {
            it = c2;
        }
    }

    return src;
}

std::wstring& Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(std::wstring & str) {



     std::map<char,int> m;
    for (size_t i =0; i < str.size(); ++i) {
        if (!m.insert( std::pair<char,int>(str[i],0)).second) {
            str.erase(i, 1); --i;
        }
    }

    return str;
}

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

