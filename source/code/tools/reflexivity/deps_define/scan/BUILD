package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(
    name = "deps_repo_scanner",
    deps = [
        "//code/literature/publish:essay_publisher",
        "//code/tools/reflexivity/bazel_wrapper:bazel_wrapper_refresher",
        "//code/tools/reflexivity/bazelrc:bazelrc_refresher",
        "//code/tools/reflexivity/deps_define:deps_definition_refresher",
        "//code/tools/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/tools/reflexivity/docker:dockerfile_refresher",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings",
        "//code/tools/reflexivity/settings:reflexive_refresh_settings_getter",
        "//code/tools/reflexivity/tool_chain_conversion:tool_chain_conversion_refresher",
        "//code/tools/transcompilers/unilang/self_readme:unilang_documentation_generator",
        "//code/utilities/code:concept_tree_to_image",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/utilities/program/name:program_name_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/github:repo_getter",
        "//code/utilities/program/wrappers/git/repo_establisher:repo_establisher",
        "//code/utilities/program/wrappers/git:lib",
        "//code/tools/reflexivity/deps_define/scan:repo_scanned_info",
    ],
)

hcp(
    name = "repo_scanned_info",
    deps = [
        "//code/utilities/web:web_json_extraction_settings",
        "//code/utilities/web:lib",
        "//code/tools/reflexivity/deps_define/data:dependency_specification",
    ],
)

