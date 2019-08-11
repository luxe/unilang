#include <iostream>
#include "code/utilities/build/self_builder.hpp"

int main(){
    
    std::cout << Self_Builder::Does_Current_Repo_Build_As_Is() << std::endl;
}