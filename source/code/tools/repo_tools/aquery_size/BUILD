package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/utilities/output/printers:lib",
        "//code/tools/repo_tools/aquery_size/program_options:lib",
        "//code/utilities/program/wrappers/bazel:bazel_runner",
        "//code/utilities/data_structures/counters/unique_counter:unique_counter",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/build/profile_parser:file_duration_extractor",
        "//code/utilities/build/build_repo_establisher:build_repo_establisher",
        "//code/utilities/build/efficient_target_deriver:target_augment_settings",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers/other:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/build/efficient_target_deriver:efficient_target_deriver",
        "//code/utilities/data_structures/fraction:fraction_parser",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
    ],
)

distributable_cpp_main(
    name = "aquery_size",
    depends = [
    ],
    description = "find sizes of files from aquery",
    deps = [
        "//code/tools/repo_tools/aquery_size:task_executer",
        "//code/tools/repo_tools/aquery_size/program_options:lib",
    ],
)