#include <iostream>
#include <string>
#include "code/tools/reflexivity/docker/dockerfile_refresher.hpp"
#include "code/tools/reflexivity/bazelrc/bazelrc_refresher.hpp"
#include "code/tools/reflexivity/bazel_wrapper/bazel_wrapper_refresher.hpp"
#include "code/tools/reflexivity/deps_define/deps_definition_refresher.hpp"
#include "code/tools/reflexivity/tool_chain_conversion/tool_chain_conversion_refresher.hpp"
#include "code/tools/reflexivity/settings/reflexive_refresh_settings.hpp"
#include "code/tools/reflexivity/settings/reflexive_refresh_settings_getter.hpp"
#include "code/utilities/locale/lib.hpp"
#include "code/utilities/program/name/program_name_getter.hpp"
#include <errno.h>


// Parts of the repository (this repository, right here) need generated programatically.  
// The reason we need to generate parts programatically, is so we can try to automatically upgrade portions of the repo infrastructure.
// Like most things, more possibilities open up, when the repo infrastructure is expressed in a data model.

//other bazel reflectivity tools:
//https://github.com/bazelbuild/buildtools
//https://github.com/spotify/bazel-tools


int main(int argc, char** argv){
    Set_English_UTF8_Locale();
    
    //what to refresh
    auto settings = Reflexive_Refresh_Settings_Getter::Get();
    
    //things within the repository that need regenerated
    
    
    //root repo stuff
    if (settings.refresh_bazel_wrapper){
        std::cout << "Generating Bazel Wrapper..." << std::endl;
        Bazel_Wrapper_Refresher::Refresh();
    }
    
    if (settings.refresh_bazelrc){
        std::cout << "Generating .bazelrc..." << std::endl;
        Bazelrc_Refresher::Refresh();
    }
    
    if (settings.refresh_dockerfile){
        std::cout << "Generating Dockerfile..." << std::endl;
        Dockerfile_Refresher::Refresh();
    }
    
    if (settings.refresh_deps_definitions){
        std::cout << "Generating 3rd party deps..." << std::endl;
        Deps_Definition_Refresher::Refresh();
    }
    
    if (settings.refresh_toolchain_conversion_tests){
        std::cout << "Generating Tool Chain Conversions..." << std::endl;
        Tool_Chain_Conversion_Refresher::Refresh();
    }
}