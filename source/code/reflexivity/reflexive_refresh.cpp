#include <iostream>
#include <string>
#include "code/reflexivity/docker/dockerfile_refresher.hpp"
#include "code/reflexivity/deps_define/deps_definition_refresher.hpp"
#include "code/reflexivity/tool_chain_conversion/tool_chain_conversion_refresher.hpp"
#include "code/reflexivity/settings/reflexive_refresh_settings.hpp"
#include "code/utilities/locale/lib.hpp"


// Parts of the repository (this repository, right here) need generated programatically.  
// The reason we need to generate parts programatically, is so we can try to automatically upgrade portions of the repo infrastructure.
// Like most things, more possibilities open up, when the repo infrastructure is expressed in a data model
int main(int argc, char** argv){
    Set_English_UTF8_Locale();
    
    //what to refresh
    Reflexive_Refresh_Settings settings;
    settings.refresh_dockerfile = true;
    settings.refresh_deps_definitions = true;
    settings.refresh_toolchain_conversion_tests = true;
    
    //things within the repository that need regenerated
    if (settings.refresh_dockerfile){
        std::cout << "Generating Dockerfile..." << std::endl;
        Dockerfile_Refresher::Refresh();
    }
    
    if (settings.refresh_deps_definitions){
        std::cout << "Definition Refresher..." << std::endl;
        Deps_Definition_Refresher::Refresh();
    }
    
    if (settings.refresh_toolchain_conversion_tests){
        std::cout << "Tool Chain Conversion Refresher..." << std::endl;
        Tool_Chain_Conversion_Refresher::Refresh();
    }
}