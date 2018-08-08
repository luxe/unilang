#include "code/utilities/types/strings/observers/comparing/lib.hpp"
#include "code/utilities/types/strings/transformers/casing/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "boost/algorithm/string/predicate.hpp"

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