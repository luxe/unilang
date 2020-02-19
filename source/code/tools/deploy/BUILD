package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "deploy",
    srcs = ["main.cpp"],
    deps = [
    "//code/utilities/program/common_actions/locale:lib",
    "//code/tools/deploy:software_deployer"
    ],
)


hcp(name = "software_deployer", deps = [
    "//code/utilities/filesystem/files/getting:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/path:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/tools/deskstock:deskstock_documentation_getter",
    "//code/tools/noogle:noogle_documentation_getter",
    "//code/tools/gcalviz:gcalviz_documentation_getter",
    "//code/tools/repo_tools/external_deps_analysis:external_deps_analysis_documentation_getter",
    "//code/tools/repo_tools/shared_object_trace:shared_object_trace_documentation_getter",
    "//code/tools/repo_tools/build_determinism:build_determinism_documentation_getter",
    "//code/tools/repo_tools/build_tools:build_tools_documentation_getter",
    
    "//code/utilities/formats/pdf:pdf_settings",
    "//code/utilities/formats/pdf:pdf_creator",
    "//code/utilities/filesystem/files/moving:lib",
    "//code/utilities/program/wrappers/git/update:git_updater",
    
    "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
    "//code/tools/transcompilers/unilang/main:program_input",
    "//code/tools/transcompilers/unilang/structure/model:structure",
    "//code/tools/transcompilers/unilang/main/root_settings:root_settings_getter",
    "//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_str_getter",
    "//code/tools/games/mario:mario_documentation_getter",
])
