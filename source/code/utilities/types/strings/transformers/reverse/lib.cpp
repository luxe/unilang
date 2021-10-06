#include "code/utilities/types/strings/transformers/reverse/lib.hpp"
#include <algorithm>

std::string& Reverse(std::string & str){
        std::reverse(std::begin(str), std::end(str));
        return str;
}
std::string As_Reversed(std::string str){
        return Reverse(str);
}