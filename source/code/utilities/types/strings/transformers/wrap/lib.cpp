#include "code/utilities/types/strings/transformers/wrap/lib.hpp"
#include <algorithm>

std::string& Wrap_In_Single_Quotes(std::string & str){
        str = "'" + str + "'";
        return str;
}
std::string As_Wrapped_In_Single_Quotes(std::string str){
        str = "'" + str + "'";
        return str;
}
std::string& Wrap_In_Double_Quotes(std::string & str){
        str = "\"" + str + "\"";
        return str;
}
std::string As_Wrapped_In_Double_Quotes(std::string str){
        str = "\"" + str + "\"";
        return str;
}
std::string& Wrap_In_Square_Brackets(std::string & str){
        str = "[" + str + "]";
        return str;
}
std::string As_Wrapped_In_Square_Brackets(std::string str){
        str = "[" + str + "]";
        return str;
}