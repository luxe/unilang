#include <iostream>
#include "code/utilities/types/strings/transformers/binary/lib.hpp"

std::string as_binary_inverted(std::string const& str){
    std::string x;
    for (auto const& it: str){
        if (it == '0'){
            x += '1';
        }
        else if (it == '1'){
            x += '0';
        }
        else {
            std::cerr << "not binary" << std::endl;
            exit(-1);
        }
    }
    return x;
}