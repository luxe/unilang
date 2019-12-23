package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "task_executer", deps = [
    "//code/utilities/shell:lib",
    "//code/utilities/printers:lib",
    "//code/tools/repo_tools/external_deps_analysis/settings:settings",
    "//code/tools/repo_tools/external_deps_analysis:analysis_state",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/types/sets:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/graphviz:graphviz_image_maker",
    "//code/tools/repo_tools/external_deps_analysis/program_options:lib",
    "//code/tools/repo_tools/external_deps_analysis/settings:settings_getter",
    "//code/utilities/bazel:bazel_runner",
    "//code/utilities/types/queue:lib",
])

hcp(name = "analysis_state", deps = [
])

hcp(name = "external_deps_analysis_documentation_getter", deps = [
    "//code/transcompilers/unilang/structure/model:inlined_structures",
    "//code/transcompilers/unilang/structure/model:structure",
    "//code/utilities/converters:lib",
    "//code/utilities/json/functions:lib",
    "//code/tools/repo_tools/external_deps_analysis/program_options:lib",
    "//code/utilities/documentation:common_documentation_getter",
])

distributable_cpp_main(
    name = "external_deps_analysis",
    deps = [
        "//code/tools/repo_tools/external_deps_analysis:task_executer",
        "//code/tools/repo_tools/external_deps_analysis/program_options:lib",
    ],
    description = "dependency graph creation for 3rd party libraries in bazel",
    depends = [
    ],
)