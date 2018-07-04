#include "body_token.hpp"










//jumbo constructor
 Body_Token::Body_Token(Body_Token_Name const& name
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
            : name(name)
            , start(start)
            , end(end)
            , bg_color(bg_color)
            , fg_color(fg_color)
            , could_be_used_as_doxygen(could_be_used_as_doxygen)
            , documentation_related(documentation_related)
            , useable_in_global(useable_in_global)
            , useable_in_object(useable_in_object)
            , groups(groups)
            , description(description)
            
            {}
            

//data members

    
