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
            

};


//specialized tokens
using Token      = Generic_Token<Token_Name,Token_Group>;
using Body_Token = Generic_Token<Body_Token_Name,Body_Token_Group>;