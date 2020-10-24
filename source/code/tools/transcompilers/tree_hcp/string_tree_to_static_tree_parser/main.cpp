#include <iostream>
#include <string>
#include "code/tools/transcompilers/tree_hcp/string_tree_to_static_tree_parser/hcp_creator.hpp"
#include "code/tools/transcompilers/tree_hcp/string_tree_to_static_tree_parser/program_options/program_options.hpp"
#include "code/utilities/program/common_actions/locale/lib.hpp"

int main(int argc, char** argv){
    
    //Unicode please
    Set_English_UTF8_Locale();

    //get program options
    auto po = Program_Options(argc,argv);

    //build it
    Hcp_Creator::Create(po.Input_File(),po.Output_Dir() + "/" + po.Name());

}
