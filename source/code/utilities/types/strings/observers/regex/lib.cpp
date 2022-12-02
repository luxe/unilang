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

std::vector<std::smatch> Get_Regex_Matches(std::vector<std::string> lines, std::string const& regex){
    std::vector<std::smatch> result;
    
    for (auto const& it: lines){
        std::smatch sm;
        std::regex_search(it, sm, std::regex(regex));
        if (!sm.empty()){
            result.emplace_back(sm);
        }
    }
    
    return result;
}