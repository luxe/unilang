#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/header_validator/lib.hpp"
#include "code/utilities/types/strings/observers/other/lib.hpp"
#include "code/utilities/types/wstrings/transformers/other/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "code/utilities/types/converters/lib.hpp"
#include "code/utilities/types/strings/observers/char/lib.hpp"
#include <iostream>





 void Header_Validator::Validate(std::string const& class_name, std::wstring const& include_name_with_possible_quotes, bool const& is_header){

    bool starts_with_quote = false;
    bool ends_with_quote = false;
    if (Begins_With(as_string(include_name_with_possible_quotes),"\"")){starts_with_quote = true;}
    if (Ends_With(as_string(include_name_with_possible_quotes),"\"")){ends_with_quote = true;}
    
    if ((starts_with_quote && !ends_with_quote) || (!starts_with_quote && ends_with_quote)){
        Exit_With_Error("If a header file has quotes in it, make sure you put the quotes on both sides");
    }
    
    //now that we have tested the possible quotes on the include statement, we can remove them for further validation processing
    std::string include_name = As_N_Chars_Removed_From_Front_And_Back(as_string(include_name_with_possible_quotes),1);
    

    //check for the inclusion of the class name
    if (as_wstring(include_name) == as_wstring(As_Removed_Suffix(class_name))){
        
        if (is_header){
            Exit_With_Error("It doesn't make sense to include the class itself. What are you trying to do- infinite recursion?");
        }else{
            Exit_With_Error("You don't need to include the class's header in the source. The compiler does this automatically for you.");
        }
    }


    //header includes must be made up of lowercase letters and underscores
    if (!Has_Only_Lowercase_Letters_And_Underscores(as_string(include_name))){
    	//let this be for now because I wasn't able to install some headers with forward slashes
    	//but also, other system libraries may use capital letters
    	//will probably want to do a different check between system and local headers
        //Exit_With_Error("header files must only have lowercase letters and underscores");
    }
}


void Header_Validator::Exit_With_Error(std::string const& str){
    std::cerr << str << std::endl;
    exit(-1);
}