package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "task_executer", deps = [
    "//code/tools/repo_tools/build_tools/settings:settings_getter",
    "//code/utilities/printers:lib",
    "//code/utilities/program/wrappers/git/repo_establisher:repo_establisher",
    "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper_deriver",
    "//code/utilities/program/wrappers/bazel/setup/config:bazel_config_deriver",
    "//code/utilities/program/wrappers/bazel:bazel_runner",
    "//code/utilities/data_structures/unique_counter:unique_counter",
    "//code/utilities/types/strings/observers/path:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/splitting:lib",
])

hcp(name = "build_tools_documentation_getter", deps = [
    "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
    "//code/tools/transcompilers/unilang/structure/model:structure",
    "//code/utilities/converters:lib",
    "//code/utilities/formats/json/functions:lib",
    "//code/tools/repo_tools/build_tools/program_options:lib",
    "//code/utilities/documentation:common_documentation_getter",
])

distributable_cpp_main(
    name = "build_tools",
    deps = [
        "//code/tools/repo_tools/build_tools:task_executer",
        "//code/tools/repo_tools/build_tools/program_options:lib",
    ],
    description = "collects all of the tools used in a build",
    depends = [
    ],
)