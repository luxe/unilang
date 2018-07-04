#pragma once
#include <string>
#include <vector>
#include "code/transcompilers/unilang/tokens/token_name.hpp"
#include "code/transcompilers/unilang/tokens/token_group.hpp"

class Token{









//jumbo constructor
public: Token(Token_Name const& name
            , wchar_t start
            , wchar_t end
            , std::string const& fg_color
            , std::string const& bg_color
            , bool const& could_be_used_as_doxygen
            , bool const& mandatory
            , bool const& documentation_related
            , bool const& multiple_tokens_allowed
            , bool const& useable_in_global
            , bool const& useable_in_object
            , bool const& can_be_root_token
            , bool const& root_token_only
            , std::vector<Token_Group> groups
            , std::string const& description)
            ;
            

//data members

Token_Name name;
wchar_t start;
wchar_t end;
std::string bg_color;
std::string fg_color;
bool could_be_used_as_doxygen;
bool mandatory;
bool documentation_related;
bool multiple_tokens_allowed;
bool useable_in_global;
bool useable_in_object;
bool can_be_root_token;
bool root_token_only;
std::vector<Token_Group> groups;
std::string description;

    
};