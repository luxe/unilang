#include "code/utilities/types/strings/transformers/casing/lib.hpp"
#include "code/utilities/types/strings/transformers/trimming/lib.hpp"
#include "code/utilities/types/strings/transformers/squeeze/lib.hpp"
#include "code/utilities/types/strings/transformers/search_replace/lib.hpp"
#include <algorithm>
#include <cctype>

//casing

std::string& CapitalizeFirstChar(std::string & s){
        if (!s.empty()){
                s[0] = toupper(s[0]);
        }
	return s;
}
std::string& LowercaseFirstChar(std::string & s){
        if (!s.empty()){
                s[0] = tolower(s[0]);
        }
		return s;
}
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





std::string As_Camel_Case(std::string s){
        return As_Capital_And_Pushed_Together(s);
}
std::string As_Lower_Camel_Case(std::string s){
        auto new_s = As_Capital_And_Pushed_Together(s);
        LowercaseFirstChar(new_s);
        return new_s;
}


std::string As_Capitalized(std::string s){
       trim(s);
       Squeeze_Away_Spaces(s); 
       
    //capitalize each letter after a space
    bool was_space = true; // <- capitalize the first character every time
    for (auto & it: s){
        if (it == ' '){
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
std::string As_Capital_And_Pushed_Together(std::string s){
        auto it = Make_Capital_And_Underscored_In_User_Type_Format(s);
        auto next = string_replace_all(it,"_","");
        return string_replace_all(next," ","");
}
std::string Capitalize_Each_With_Space_In_Between(std::string s){
        auto it = Make_Capital_And_Underscored_In_User_Type_Format(s);
        return string_replace_all(it,"_"," ");
}

std::string Make_Capital_And_Underscored_In_User_Type_Format(std::string s) {

    trim(s);
    Squeeze_Away_Spaces(s);

    //turn spaces into underscores and capitalize each letter
    bool was_space = true; // <- capitalize the first character every time
    for (auto & it: s){
        if (it == ' ' || it == '_'){
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

std::string As_Capital_And_Pushed_Together_Preserve_Underscores_With_Lowercase_After(std::string s){
        auto str = As_Capitalized(s);
        return string_replace_all(str," ","");
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
std::string As_All_Lowercase_Letters_With_Spaces_As_Underscores(std::string s){
    trim(s);
    Squeeze_Away_Spaces(s);
    for (auto & it: s){
        if (it == ' '){ it ='_'; }
        else { it = static_cast<char>(tolower(it)); }
    }

    return s;
}
std::string As_All_Lowercase_Letters_With_Underscores_As_Spaces(std::string s){
    trim(s);
    Squeeze_Away_Spaces(s);
    for (auto & it: s){
        if (it == '_'){ it =' '; }
        else { it = static_cast<char>(tolower(it)); }
    }

    return s;
}