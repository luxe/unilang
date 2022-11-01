#include "code/utilities/types/strings/observers/comparing/lib.hpp"
#include "code/utilities/types/strings/transformers/casing/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "boost/algorithm/string/predicate.hpp"
#include "levenshtein.h"
#include <sstream>

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
bool Case_Insensitive_Alpha_Compare(std::string str1, std::string str2){
	auto new_str1 = As_NonAlphas_Removed(str1);
	auto new_str2 = As_NonAlphas_Removed(str2);
	return Case_Insensitive_String_Compare(new_str1,new_str2);
}

bool Non_Case_Sensitive_Compare(std::string str1, std::string str2){
	return (Lowercase(str1) == Lowercase(str2));
}
bool Case_Sensitive_Compare(std::string const& str1, std::string const& str2){
	return (str1 == str2);
}

size_t Levenshtein_Distance(std::string const& str1, std::string const& str2){
	return levenshtein_n(str1.c_str(), str1.size(), str2.c_str(), str2.size());
}

bool Numerical_String_Compare(const std::string& s1, const std::string& s2)
{
    //handle digit size differences
    if (s1.size() < s2.size()){
        return true;
    }
    if (s1.size() > s2.size()){
        return false;
    }
    
    //compare digits individually
    for (size_t i = 0; i < s1.size(); ++i){
        char c1 = s1[i];
        char c2 = s2[i];
        if (c1 != c2){
            return c1 < c2;
        }
    }
    
    //they are equivalent
    return false;
}