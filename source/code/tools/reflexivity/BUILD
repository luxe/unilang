package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

cpp_main(
    name = "reflexive_refresh",
    deps = [
        "//code/literature/publish:essay_publisher",
        "//code/tools/reflexivity:reflexive_refresher",
        "//code/tools/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/tools/reflexivity/bazelrc:bazelrc_refresher",
        "//code/tools/reflexivity/deps_define/refresh:deps_definition_refresher",
        "//code/tools/reflexivity/docker:dockerfile_refresher",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/tools/reflexivity/tool_chain_conversion:tool_chain_conversion_refresher",
        "//code/tools/transcompilers/unilang/self_readme:unilang_documentation_generator",
        "//code/utilities/code:concept_tree_to_image",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/utilities/program/name:program_name_getter",
    ],
)

cpp_main(
    name = "build_gen",
    deps = [
        "//code/tools/reflexivity:target_build_file_refresher",
        "//code/tools/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/tools/reflexivity/bazelrc:bazelrc_refresher",
        "//code/tools/reflexivity/deps_define/refresh:deps_definition_refresher",
        "//code/tools/reflexivity/docker:dockerfile_refresher",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/tools/reflexivity/tool_chain_conversion:tool_chain_conversion_refresher",
        "//code/utilities/program/common_actions/locale:lib",
    ],
)

cpp_main(
    name = "concept_tree",
    deps = [
        "//code/utilities/code:concept_tree_to_image",
        "//code/utilities/filesystem/paths:lib",
    ],
)

hcp(
    name = "reflexive_refresher",
    deps = [
        "//code/literature/publish:essay_publisher",
        "//code/tools/reflexivity:target_build_file_refresher",
        "//code/tools/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/tools/reflexivity/bazelrc:bazelrc_refresher",
        "//code/tools/reflexivity/deps_define/refresh:deps_definition_refresher",
        "//code/tools/reflexivity/deps_define/scan:deps_repo_scanner",
        "//code/tools/reflexivity/docker:dockerfile_refresher",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/tools/reflexivity/tool_chain_conversion:tool_chain_conversion_refresher",
        "//code/tools/transcompilers/unilang/self_readme:unilang_documentation_generator",
        "//code/utilities/build:self_builder",
        "//code/utilities/code:concept_tree_to_image",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/utilities/program/name:program_name_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "target_build_file_refresher",
    deps = [
        "//code/tools/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/tools/reflexivity/bazelrc:bazelrc_refresher",
        "//code/tools/reflexivity/deps_define/refresh:deps_definition_refresher",
        "//code/tools/reflexivity/docker:dockerfile_refresher",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/tools/reflexivity/tool_chain_conversion:tool_chain_conversion_refresher",
        "//code/utilities/build:self_builder",
    ],
)
