#include <iostream>
#include <locale>
#include <clocale>
#include "code/utilities/program/common_actions/locale/lib.hpp"
void Set_English_UTF8_Locale(){

    //setlocale(LC_ALL, "en_US.UTF-8");
    std::locale::global(std::locale("en_US.UTF-8"));
    std::cout.imbue(std::locale("en_US.utf8"));
}
