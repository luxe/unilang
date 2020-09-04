package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

distributable_cpp_main(
    name = "build_third_party_lib",
    depends = [
    ],
    description = "build a third party library in parts",
    deps = [
        "//code/tools/repo_tools/build_third_party_lib:task_executer",
        "//code/tools/repo_tools/build_third_party_lib/program_options:lib",
    ],
)

hcp(
    name = "task_executer",
    deps = [
        "//code/tools/repo_tools/build_third_party_lib/program_options:lib",
        "//code/utilities/build/profiler/data:profile_settings",
        "//code/utilities/build/profiler/data:profile_results",
        "//code/utilities/program/wrappers/git:branch_switcher",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/build/profiler:branch_profile_compilation_timer",
        "//code/utilities/math:math",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/build/build_repo_establisher:build_repo_establisher",
        "//code/utilities/program/wrappers/bazel/query:bazel_query_runner",
    ],
)