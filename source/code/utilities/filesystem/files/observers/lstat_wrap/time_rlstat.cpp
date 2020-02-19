#include <iostream>
#include <iomanip>
#include "code/utilities/filesystem/files/observers/lstat_wrap/lib.hpp"

int main(int argc, char *argv[]){
    std::cout << std::boolalpha;
    auto m = RecursiveLstat(argv[1]);
    std::cout << m.size() << std::endl;
}
