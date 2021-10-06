#include <iostream>
#include "code/utilities/web/chrome/version/chrome_version_getter.hpp"

int main(){
    auto version = Chrome_Version_Getter::Get_Version();
    std::cout << version << std::endl;
}
