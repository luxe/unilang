#include <iostream>
#include <cstdlib>
#include "code/utilities/compression/lib.hpp"

int main(int const argc, char** const argv){
    
    auto sha = Sha256sum_Of_Url_Artifact(argv[1]);
    std::cout << sha << std::endl;
}