#include <iostream>
#include <iomanip>
#include "code/utilities/build/self_builder.hpp"

int main(){
    
    std::cout << std::boolalpha << Self_Builder::Does_Current_Repo_Build_As_Is() << std::endl;
}