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
        "//code/utilities/build/parse_profile:file_duration_extractor",
        "//code/utilities/program/wrappers/bazel/setup:default_bazel_setup_settings",
        "//code/utilities/program/wrappers/git/repo_establisher:default_repo_location_getter",
        "//code/utilities/program/wrappers/bazel/setup:bazel_setup_deriver",
        "//code/utilities/program/wrappers/bazel:default_build_settings",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/build/build_repo_establisher:build_repo_establisher",
        "//code/tools/repo_tools/bazel_profile_slow_cc_files:results_publisher",
    ],
)

hcp(
    name = "results_publisher",
    deps = [
        "//code/utilities/output/printers:lib",
        "//code/tools/repo_tools/bazel_profile_slow_cc_files/program_options:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/web/honeycomb:honeycomb_poster",
        "//code/utilities/build/parse_profile:file_duration_extractor",
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


hcp(
    name = "bazel_profile_slow_cc_files_documentation_getter",
    deps = [
        "//code/tools/repo_tools/bazel_profile_slow_cc_files/program_options:lib",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/documentation:common_documentation_getter",
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/types/converters:lib",
    ],
)