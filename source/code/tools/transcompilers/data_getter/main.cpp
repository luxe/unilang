#include <iostream>
#include <string>
#include "code/tools/transcompilers/data_getter/program_options/program_options.hpp"
#include "code/tools/transcompilers/hcp-compiler/programatic/data/code.hpp"
#include "code/tools/transcompilers/hcp-compiler/programatic/code_getter.hpp"

Code Build_Code(Program_Options const& po){

    Code x;
    
    x.headers.public_headers.emplace_back("string");
    
    Function f;
    f.name = "Get";
    f.return_val = "std::string";
    f.body += "return ";
    f.body += "\"";
    f.body += po.Input_File();
    f.body += "\"";
    f.body += ";";
    
    x.functions.emplace_back(f);
    
    return x;
}

int main(int argc, char** argv){

    //get program options
    Program_Options po = Program_Options(argc,argv);
    
    Code x = Build_Code(po);
    
    auto text = Code_Getter::Get(x);
    
}