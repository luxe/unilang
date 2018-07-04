#pragma once
#include <string>
#include <vector>
#include "code/transcompilers/unilang/tokens/token_name.hpp"
#include "code/transcompilers/unilang/tokens/token_group.hpp"

class Body_Token{









//jumbo constructor
public: Body_Token(Body_Token_Name const& name
            , wchar_t start
            , wchar_t end
            , std::string const& fg_color
            , std::string const& bg_color
            , bool const& could_be_used_as_doxygen
            , bool const& documentation_related
            , bool const& useable_in_global
            , bool const& useable_in_object
            , std::vector<Body_Token_Group> groups
            , std::string const& description)
            ;
            

//data members

Body_Token_Name name;
wchar_t start;
wchar_t end;
std::string bg_color;
std::string fg_color;
bool could_be_used_as_doxygen;
bool documentation_related;
bool useable_in_global;
bool useable_in_object;
std::vector<Body_Token_Group> groups;
std::string description;

    
};