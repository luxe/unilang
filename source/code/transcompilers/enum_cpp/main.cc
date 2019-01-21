#include <iostream>
#include <string>
#include "code/transcompilers/enum_cpp/enum_cpp_maker.hpp"
#include "code/transcompilers/enum_cpp/program_options/program_options_creator.hpp"

int main(int argc, char** argv){
    auto po = Program_Options_Creator::Create(argc,argv);
}
