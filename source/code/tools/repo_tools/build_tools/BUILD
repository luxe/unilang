package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/tools/repo_tools/build_tools/settings:settings_getter",
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/bazel:bazel_runner",
        "//code/utilities/program/wrappers/bazel/setup/config:bazel_config_deriver",
        "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper_deriver",
        "//code/utilities/program/wrappers/git/repo_establisher",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)

hcp(
    name = "build_tools_documentation_getter",
    deps = [
        "//code/tools/repo_tools/build_tools/program_options:lib",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/documentation:common_documentation_getter",
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/types/converters:lib",
    ],
)

distributable_cpp_main(
    name = "build_tools",
    depends = [
    ],
    description = "collects all of the tools used in a build",
    deps = [
        "//code/tools/repo_tools/build_tools:task_executer",
        "//code/tools/repo_tools/build_tools/program_options:lib",
    ],
)
