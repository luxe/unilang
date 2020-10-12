#include <iostream>
#include <string>
#include "code/tools/transcompilers/tree_hcp/string_tree_getter/hcp_maker.hpp"
#include "code/tools/transcompilers/tree_hcp/string_tree_getter/program_options/program_options.hpp"

int main(int argc, char** argv){

    //get program options
    auto po = Program_Options(argc,argv);

    auto path_name = po.Name();
    if (!po.Output_Path().empty()){
        path_name = po.Output_Path() + "/" + path_name;
    }
    
    std::string data;

    //build it
    Hcp_Maker::Create(path_name,data);

}
