#include "code/utilities/types/strings/observers/regex/lib.hpp"
#include <regex>

bool Matches_Regex(std::string const& str, std::string const& regex){
    std::regex obj_regex(regex);
    return std::regex_match(str, obj_regex);
}

bool Matches_Any_Regex(std::string const& str, std::vector<std::regex> const& regexes){
    
    for (auto it: regexes){
        if (std::regex_match(str, it)){
            return true;
        }
    }
    return false;
}