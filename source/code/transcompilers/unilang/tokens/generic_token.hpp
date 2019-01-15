#pragma once
#include <string>
#include <vector>
#include "code/transcompilers/unilang/tokens/token_name.hpp"
#include "code/transcompilers/unilang/tokens/token_group.hpp"

template <typename Token_Name_Type, typename Token_Group_Type>
class Generic_Token{



public:
//data members
Token_Name_Type name;
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
std::vector<Token_Group_Type> groups;
std::string description; 


public: Generic_Token(Token_Name_Type const& name
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
            , std::vector<Token_Group_Type> groups
            , std::string const& description)
            : name(name)
            , start(start)
            , end(end)
            , bg_color(bg_color)
            , fg_color(fg_color)
            , could_be_used_as_doxygen(could_be_used_as_doxygen)
            , mandatory(mandatory)
            , documentation_related(documentation_related)
            , multiple_tokens_allowed(multiple_tokens_allowed)
            , useable_in_global(useable_in_global)
            , useable_in_object(useable_in_object)
            , can_be_root_token(can_be_root_token)
            , root_token_only(root_token_only)
            , groups(groups)
            , description(description)
            
            {}
      
      Generic_Token(){}
            

};


//specialized tokens
using Token      = Generic_Token<Token_Name,Token_Group>;
using Body_Token = Generic_Token<Body_Token_Name,Body_Token_Group>;