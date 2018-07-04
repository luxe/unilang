#include "token.hpp"










//jumbo constructor
 Token::Token(Token_Name const& name
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
            

//data members

    
