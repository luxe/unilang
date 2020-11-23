#include <iostream>
#include "code/tools/nvidia/arch_pruner.hpp"
#include "code/tools/nvidia/arch_prune_settings.hpp"
#include "code/tools/nvidia/program_options/program_options.hpp"

int main(int const argc, char** const argv){
    
    //create arch prune settings
    Program_Options program_options(argc, argv);
    Arch_Prune_Settings settings;
    settings.file_name = program_options.File();
    settings.keep_archs = program_options.Keep();
    settings.skip_archs = program_options.Skip();
    
    Arch_Pruner::Prune(settings);
}
