package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

cpp_main(
    name = "reflexive_refresh",
    deps = [
        "//code/tools/reflexivity/docker:dockerfile_refresher",
        "//code/tools/reflexivity/bazelrc:bazelrc_refresher",
        "//code/tools/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/tools/reflexivity/deps_define:deps_definition_refresher",
        "//code/tools/reflexivity/tool_chain_conversion:tool_chain_conversion_refresher",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/utilities/program/name:program_name_getter",
        "//code/tools/transcompilers/unilang/self_readme:unilang_documentation_generator",
        "//code/literature/publish:essay_publisher",
        "//code/utilities/code:concept_tree_to_image",
    ],
)
