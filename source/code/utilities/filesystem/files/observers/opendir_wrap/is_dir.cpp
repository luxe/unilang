#include <iostream>
#include <iomanip>
#include "code/utilities/filesystem/files/observers/opendir_wrap/opendir_wrap.hpp"

int main(int argc, char *argv[]){
    std::cout << std::boolalpha;
    std::cout << Opendir_Wrap::Is_Directory(argv[1]) << std::endl;
}
