#include "lib.hpp"
#include <iostream>

void Exit_With_Error(std::string const& str){
    std::cerr << str << std::endl;
    exit(-1);
}