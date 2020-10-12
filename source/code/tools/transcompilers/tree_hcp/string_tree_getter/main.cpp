#include <iostream>
#include <string>
#include "code/tools/transcompilers/tree_hcp/string_tree_getter/hcp_maker.hpp"
#include "code/tools/transcompilers/tree_hcp/string_tree_getter/program_options/program_options.hpp"

int main(int argc, char** argv){

    //get program options
    auto po = Program_Options(argc,argv);

    //build it
    Hcp_Maker::Create(po.Output_Path(),po.Input_File());

}
