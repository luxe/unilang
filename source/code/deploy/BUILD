load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "deploy",
    srcs = ["main.cpp"],
    deps = [
    "//code/utilities/locale:lib",
    "//code/deploy:software_deployer"
    ],
)


hcp(name = "software_deployer", deps = [
    "//code/utilities/filesystem/files/getting:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/path:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/tools/deskstock:deskstock_documentation_getter",
    "//code/tools/noogle:noogle_documentation_getter",
    
    "//code/utilities/pdf:pdf_settings",
    "//code/utilities/pdf:pdf_creator",
    "//code/utilities/filesystem/files/moving:lib",
    "//code/utilities/git-related:git_updater",
    
    "//code/transcompilers/unilang/structure/model:inlined_structures",
    "//code/transcompilers/unilang/main:program_input",
    "//code/transcompilers/unilang/structure/model:structure",
    "//code/transcompilers/unilang/main/root_settings:root_settings_getter",
    "//code/transcompilers/unilang/compiler-frontends/markdown:markdown_str_getter",
    "//code/tools/mario:mario_documentation_getter",
])
