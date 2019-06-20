#include <iostream>
#include "code/tools/noogle/meta_settings.hpp"
#include "code/tools/noogle/noogle_runner.hpp"
#include "code/tools/noogle/program_options/program_options.hpp"

int main(int const argc, char** const argv){
    
    Meta_Settings meta;
    meta.program_name = "noogle";
    
    Program_Options program_options(argc, argv);
    Noogle_Runner::Run(meta,program_options);
}
