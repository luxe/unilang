#include <sstream>
#include <cctype>
#include <map>
#include <utility>

//casing
std::string& Uppercase(std::string &str){
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}
std::string& Lowercase(std::string &str){
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
std::string As_Uppercase(std::string str){
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}
std::string As_Lowercase(std::string str){
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

//transforming string functions
std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}
std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}
std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}
std::string& Squeeze_Away_Spaces(std::string &s){
	std::string::iterator new_end = std::unique(s.begin(), s.end(), [](char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); });
	s.erase(new_end, s.end());
	return s;
}
std::string& Remove_Suffix(std::string &s) {
	auto it = s.rfind(".");
	if (it !=  std::string::npos) {
		s.erase(it, s.size());
	}
	return s;
}
std::string As_Removed_Suffix(std::string s) {
	auto it = s.rfind(".");
	if (it !=  std::string::npos) {
		s.erase(it, s.size());
	}
	return s;
}

//basically: trim->squeeze away spaces->turn spaces into underscores->capitalize each letter
std::string Make_Capital_And_Underscored_In_User_Type_Format(std::string s) {

	trim(s);
	Squeeze_Away_Spaces(s);

	//turn spaces into underscores and capitalize each letter
	bool was_space = true; // <- capitalize the first character every time
	for (auto & it: s){
		if (it == ' '){
			it ='_';
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
std::string As_All_Capital_Letters_With_Spaces_As_Underscores(std::string s) {

	trim(s);
	Squeeze_Away_Spaces(s);
	for (auto & it: s){
		if (it == ' '){ it ='_'; }
		else { it = static_cast<char>(toupper(it)); }
	}

	return s;
}
std::string string_replace_first_instance( std::string src, std::string const& target, std::string const& repl){
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
std::string string_replace_all( std::string src, std::string const& target, std::string const& repl){

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
		if (idx == std::string::npos)  break;

		src.replace( idx, target.length(), repl);
		idx += repl.length();
	}

	return src;
}

std::string& replace_all( std::string & src, char const& c1, char const& c2) {
	for (auto & it: src) {
		if (it ==  c1) {
			it = c2;
		}
	}

	return src;
}

std::string& Remove_Duplicate_Chars_But_Keep_First_Instances_Of_Them(std::string & str) {



	 std::map<char,int> m;
	for (int i =0; i < str.size(); ++i) {
		if (!m.insert( std::pair<char,int>(str[i],0)).second) {
			str.erase(i, 1); --i;
		}
	}

	return str;
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
