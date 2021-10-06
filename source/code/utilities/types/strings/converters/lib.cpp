#include "code/utilities/types/strings/converters/lib.hpp"

char* AsAllocatedCStar(std::string const& str){
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    return cstr;
}