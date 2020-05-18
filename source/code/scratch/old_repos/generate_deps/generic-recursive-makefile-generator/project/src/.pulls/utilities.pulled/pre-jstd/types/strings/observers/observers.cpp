#include <sstream>
#include <cctype>
#include <map>
#include <utility>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>

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

//comparing two string
bool Case_Insensitive_String_Compare(std::string const& str1, std::string const& str2){
	return boost::iequals(str1, str2);
}
bool Case_Insensitive_Undercore_Ignoring_String_Compare(std::string str1, std::string str2){
	Remove_All_Instances_Of_Char(str1,'_');
	Remove_All_Instances_Of_Char(str2,'_');
	return Case_Insensitive_String_Compare(str1,str2);
}
bool Case_Insensitive_Undercore_And_Space_Ignoring_String_Compare(std::string str1, std::string str2){
	Remove_All_Instances_Of_Char(str1,'_');
	Remove_All_Instances_Of_Char(str2,'_');
	Remove_All_Instances_Of_Char(str1,' ');
	Remove_All_Instances_Of_Char(str2,' ');
	return Case_Insensitive_String_Compare(str1,str2);	
}


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
bool Has_Only_Lowercase_Letters_Underscores_And_Forward_Slashes(std::string const& str){
    for (auto const& it: str){
        if (!Is_A_Lowercase_Character(it) && it != '_' && it != '/'){return false;}
    }
    return true;
}
bool Has_Only_Uppercase_Letters_Underscores_And_Forward_Slashes(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Uppercase_Character(it) && it != '_' && it != '/'){return false;}
    }
    return true;
}
bool Has_Only_Alpha_Letters_And_Underscores(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Alpha_Character(it) && it != '_' ){return false;}
    }
    return true;	
}
bool Has_Only_Uppercase_Letters_Numbers_And_Underscores(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Uppercase_Character(it) && it != '_' && !Is_A_Numeric_Character(it) ){return false;}
    }
    return true;
}

bool Has_Only_Alphanumeric_And_Underscores(std::string const& str){
    for (auto const& it: str){
        if (!Is_An_Alphanumberic_Character(it) && it != '_' ){return false;}
    }
    return true;	
}

bool Starts_With_Digit(std::string const& str){
	if (!str.empty()){
		if (Is_A_Numeric_Character(str[0])){
			return true;
		}
	}
	return false;
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

//comparing
bool Non_Case_Sensitive_Compare(std::string str1, std::string str2){
	return (Lowercase(str1) == Lowercase(str2));
}
bool Case_Sensitive_Compare(std::string const& str1, std::string const& str2){
	return (str1 == str2);
}
bool Case_Insensitive_Alpha_Compare(std::string str1, std::string str2){
	auto new_str1 = As_NonAlphas_Removed(str1);
	auto new_str2 = As_NonAlphas_Removed(str2);
	return Case_Insensitive_String_Compare(new_str1,new_str2);
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
char First_Char(std::string const& str){
    return str[0];
}
char Last_Char(std::string const& str){
    return str[str.size()-1];
}
bool IsPalindrome(std::string str){
  return std::equal(str.cbegin(),str.cbegin() + str.size()/2,str.crbegin(),[](const char& a, const char& b){return a == b;});
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

std::vector<std::string> Split_Into_Parts_From_Delimiter(std::string const& str, char const& delimiter){
	std::vector<std::string> parts;
	
	std::string part;
	for (auto const& c: str){
		if (c == delimiter){
			parts.push_back(part);
			part.clear();
		}else{
			part+=c;
		}
	}

	if (!part.empty()){
		parts.push_back(part);
	}
	return parts;
 }
std::vector<std::string> Split_Into_Parts_From_Comma(std::string const& str){
	return Split_Into_Parts_From_Delimiter(str,',');
}
 std::vector<std::string> Get_Path_In_Parts(std::string const& str){
 	return Split_Into_Parts_From_Delimiter(str,'/');
 }
 
 std::pair<std::string,std::string> Split_On_First_Instance_Of_Char(std::string const& str, char const& c){
 	 std::pair<std::string,std::string> results;
 	 std::string first;
 	 std::string second;
 	 bool found = false;
 	 for (auto it: str){
 	 	if (!found){
 	 		first += it;
 	 	}else{
 	 		second += it;
 	 	}
 	 	
 	 	
 	 	if (it == c){
 	 		found = true;
 	 	}
 	 	
 	 }
 	 
 	 results.first = first;
 	 results.second = second;
 	 
 	 return results;
 }
 std::pair<std::string,std::string> Split_On_Second_Instance_Of_Char(std::string const& str, char const& c){
 	 std::pair<std::string,std::string> results;
 	 std::string first;
 	 std::string second;
 	 int found = 0;
 	 for (auto it: str){
 	 	if (found < 2){
 	 		first += it;
 	 	}else{
 	 		second += it;
 	 	}
 	 	
 	 	
 	 	if (it == c){
 	 		found++;
 	 	}
 	 	
 	 }
 	 
 	 results.first = first;
 	 results.second = second;
 	 
 	 return results;
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
bool File_Has_Extension(std::string const& path_to_file, std::string const& file_extension){
	return Get_File_Extension(path_to_file) == file_extension;
}
bool File_Has_Extension(std::string const& path_to_file){
	return Contains(path_to_file,'.');
}

std::string Get_File_Name(std::string const& str){
    std::string filename;
    
    for (auto const& it : boost::adaptors::reverse(str)){
        if (it == '/'){
            break;
        }else{
            filename=it+filename;
        }
    }
    
    return filename;
}

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
unsigned int Count_Instances_Of_Character(std::string const& s, char const& c) {
    unsigned int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            ++count;
        }
    }

    return count;
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

size_t Get_Index_After_Found_Substring(std::string const& str, std::string const& substring){
	auto found = str.find(substring);
	found += substring.size();
	return found;
}




//parsing out columns
std::vector<std::string> Get_Each_Column(std::string const& str){
	std::istringstream is{ str };
	const std::vector<std::string> parts{ std::istream_iterator<std::string>(is), std::istream_iterator<std::string>() };
	return parts;
}
std::string Get_Column_By_Index(std::string const& str, int index){
    return Get_Each_Column(str)[index];
}
std::string Get_1st_Column(std::string const& str){
	return Get_Column_By_Index(str,0);
}
std::string Get_2nd_Column(std::string const& str){
	return Get_Column_By_Index(str,1);
}
std::string Get_3rd_Column(std::string const& str){
	return Get_Column_By_Index(str,2);
}
std::string Get_4th_Column(std::string const& str){
	return Get_Column_By_Index(str,3);
}
std::string Get_5th_Column(std::string const& str){
	return Get_Column_By_Index(str,4);
}
