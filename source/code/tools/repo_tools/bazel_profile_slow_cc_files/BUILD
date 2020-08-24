package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/tools/repo_tools/bazel_profile_slow_cc_files/program_options:lib",
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/bazel:bazel_runner",
        "//code/utilities/program/wrappers/bazel/setup/config:bazel_config_deriver",
        "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper_deriver",
        "//code/utilities/program/wrappers/git/repo_establisher",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/other:lib",
    ],
)

distributable_cpp_main(
    name = "bazel_profile_slow_cc_files",
    depends = [
    ],
    description = "parse bazel's profile file to find slow cc files with highest compilation times",
    deps = [
        "//code/tools/repo_tools/bazel_profile_slow_cc_files:task_executer",
        "//code/tools/repo_tools/bazel_profile_slow_cc_files/program_options:lib",
    ],
)
