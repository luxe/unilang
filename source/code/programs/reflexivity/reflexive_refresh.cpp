#include <iostream>
#include <string>
#include "code/programs/reflexivity/docker/dockerfile_refresher.hpp"
#include "code/programs/reflexivity/bazelrc/bazelrc_refresher.hpp"
#include "code/programs/reflexivity/bazel_wrapper/bazel_wrapper_refresher.hpp"
#include "code/programs/reflexivity/deps_define/refresh/deps_definition_refresher.hpp"
#include "code/programs/reflexivity/settings/reflexive_refresh_settings.hpp"
#include "code/programs/reflexivity/settings/reflexive_refresh_settings_getter.hpp"
#include "code/utilities/program/common_actions/locale/lib.hpp"
#include "code/utilities/program/name/program_name_getter.hpp"
#include "code/utilities/output/publisher/essay/essay_publisher.hpp"
#include "code/utilities/code/artifacts/concept_tree/concept_tree_to_image.hpp"
#include <errno.h>
#include "code/programs/reflexivity/reflexive_refresher.hpp"
#include "code/utilities/program/common_actions/main/catching_main.hpp"


int main(int argc, char** argv){
    
    return Catching_Main::Run([&](){
        Reflexive_Refresher::Refresh();
        return 0;
    });
}