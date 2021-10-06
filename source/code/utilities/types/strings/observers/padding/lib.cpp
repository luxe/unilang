#include "code/utilities/types/strings/observers/padding/lib.hpp"

std::string pad_str_to_length(std::string str, size_t length, char c)
{
    auto current_length = str.size();
    for (size_t i = current_length; i < length; ++i){
        str += c;
    }
    return str;
}