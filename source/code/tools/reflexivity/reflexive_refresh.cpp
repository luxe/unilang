#include <iostream>
#include <string>
#include "code/tools/reflexivity/docker/dockerfile_refresher.hpp"
#include "code/tools/reflexivity/bazelrc/bazelrc_refresher.hpp"
#include "code/tools/reflexivity/bazel_wrapper/bazel_wrapper_refresher.hpp"
#include "code/tools/reflexivity/deps_define/refresh/deps_definition_refresher.hpp"
#include "code/tools/reflexivity/tool_chain_conversion/tool_chain_conversion_refresher.hpp"
#include "code/tools/reflexivity/settings/reflexive_refresh_settings.hpp"
#include "code/tools/reflexivity/settings/reflexive_refresh_settings_getter.hpp"
#include "code/utilities/program/common_actions/locale/lib.hpp"
#include "code/utilities/program/name/program_name_getter.hpp"
#include "code/tools/transcompilers/unilang/self_readme/unilang_documentation_generator.hpp"
#include "code/literature/publish/essay_publisher.hpp"
#include "code/utilities/code/concept_tree_to_image.hpp"
#include <errno.h>
#include "code/tools/reflexivity/reflexive_refresher.hpp"


int main(int argc, char** argv){
    
    auto settings = Reflexive_Refresh_Settings_Getter::Get();
    Reflexive_Refresher::Refresh(settings);
}