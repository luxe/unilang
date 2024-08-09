package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/visibility_adjuster/program_options:lib",
        "//code/utilities/build/profiler:profile_compilation_timer",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/header_detection:cpp_header_detector",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/streams/filestreams/write_all:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/types/strings/observers/regex:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
    ],
)

distributable_cpp_main(
    name = "visibility_adjuster",
    depends = [
    ],
    description = "adjusts visibility on bazel BUILD files",
    deps = [
        "//code/programs/repo_tools/visibility_adjuster:task_executer",
        "//code/programs/repo_tools/visibility_adjuster/program_options:lib",
    ],
)
