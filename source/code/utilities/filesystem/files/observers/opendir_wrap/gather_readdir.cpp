#include <iostream>
#include <iomanip>
#include "code/utilities/filesystem/files/observers/opendir_wrap/opendir_wrap.hpp"

int main(int argc, char *argv[]){
    std::cout << std::boolalpha;
    
    std::vector<std::string> dirs;
    auto m = Opendir_Wrap::Gather_Readdir_Seperate_Dirs(argv[1],dirs);
    std::cout << m.size() << " " << dirs.size() << std::endl;
}
