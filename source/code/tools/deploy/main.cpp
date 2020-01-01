#include <iostream>
#include <string>
#include "code/utilities/locale/lib.hpp"
#include "code/tools/deploy/software_deployer.hpp"

int main(int argc, char** argv){
    Set_English_UTF8_Locale();
    
    //things to export out of the repository
    Software_Deployer::Deploy();
}