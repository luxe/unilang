#include "code/utilities/types/strings/transformers/squeeze/lib.hpp"
#include <algorithm>

std::string& Squeeze_Away_Spaces(std::string &s){
    std::string::iterator new_end = std::unique(s.begin(), s.end(), [](char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); });
    s.erase(new_end, s.end());
    return s;
}
std::string As_Spaces_Squeezed_Away(std::string s){
    std::string::iterator new_end = std::unique(s.begin(), s.end(), [](char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); });
    s.erase(new_end, s.end());
    return s;
}
std::string& Squeeze_Away_Spaces_On_String(std::string &s){
    return Squeeze_Away_Spaces(s);
}

std::string squeeze_letters(std::string str){
    
    if (str.empty()){
        return "";
    }
    
    std::string new_str;
    new_str = str[0];
    
    for (size_t i = 1; i < str.size(); ++i){
        if (str[i] != str[i-1]){
                new_str += str[i];
        }
    }
    return new_str;
}