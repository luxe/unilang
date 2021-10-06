#include "code/utilities/types/strings/transformers/escape/lib.hpp"
#include "code/utilities/language_basic/multiple_relational_comparing/lib.hpp"
#include <algorithm>

std::string& Escape_Double_Quote_String_Content_For_Shell(std::string & str){
        std::string new_string;
        for (auto const& it: str){
                if (it == None_Of('!','$','"','\\')){
                        new_string += it;
                }else{
                        new_string += '\\';
                        new_string += it;
                }
        }
        str = new_string;
        return str;
}
std::string As_Escaped_Double_Quote_String_Content_For_Shell(std::string str){
        std::string new_string;
        for (auto const& it: str){
                if (it == None_Of('!','$','"','\\')){
                        new_string += it;
                }else{
                        new_string += '\\';
                        new_string += it;
                }
        }
        return new_string;
}
std::string& Escape_Single_Quote_String_Content_For_Shell(std::string & str){
        std::string new_string;
        for (auto const& it: str){
                if (it == None_Of('\'')){
                        new_string += it;
                }else{
                        new_string += "'\"'\"'";
                }
        }
        str = new_string;
        return str;
}
std::string As_Escaped_Single_Quote_String_Content_For_Shell(std::string str){
        std::string new_string;
        for (auto const& it: str){
                if (it == None_Of('\'')){
                        new_string += it;
                }else{
                        new_string += "'\"'\"'";
                }
        }
        return new_string;
}