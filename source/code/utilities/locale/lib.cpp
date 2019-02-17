#include <iostream>
#include <locale>
#include "code/utilities/locale/lib.hpp"
void Set_English_UTF8_Locale(){

    std::locale::global(std::locale("en_US.UTF-8"));
    std::cout.imbue(std::locale("en_US.utf8"));
}
