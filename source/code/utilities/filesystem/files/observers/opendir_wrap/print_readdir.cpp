#include <iostream>
#include <iomanip>
#include "code/utilities/filesystem/files/observers/opendir_wrap/opendir_wrap.hpp"

int main(int argc, char *argv[]){
    std::cout << std::boolalpha;
    Opendir_Wrap::Print_Readdir(argv[1]);
}
