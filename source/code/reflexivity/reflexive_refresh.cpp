#include <iostream>
#include <string>
#include "code/reflexivity/docker/dockerfile_refresher.hpp"
#include "code/reflexivity/deps_define/deps_definition_refresher.hpp"
#include "code/reflexivity/tool_chain_conversion/tool_chain_conversion_refresher.hpp"
#include "code/utilities/locale/lib.hpp"


// Parts of the repository (this repository, right here) need generated programatically.  
// The reason we need to generate parts programatically, is so we can try to automatically upgrade portions of the repo infrastructure.
// Like most things, more possibilities open up, when the repo infrastructure is expressed in a data model
int main(int argc, char** argv){
    Set_English_UTF8_Locale();
    
    //things within the repository that need regenerated
    std::cout << "generating Dockerfile..." << std::endl;
    Dockerfile_Refresher::Refresh();
    
    std::cout << "Definition Refresher..." << std::endl;
    Deps_Definition_Refresher::Refresh();
    
    std::cout << "Tool Chain Conversion Refresher..." << std::endl;
    Tool_Chain_Conversion_Refresher::Refresh();
}