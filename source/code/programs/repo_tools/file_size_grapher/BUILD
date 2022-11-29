package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/file_size_grapher/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/git/commits:git_all_file_commits",
        "//code/utilities/types/strings/observers/counters:lib",
    ],
)

# Track the size of a file over time.  This is useful when files represent denylists.
# Ideally the file should be size zero, and we want to track which way the file entries are trending.
distributable_cpp_main(
    name = "file_size_grapher",
    depends = [
    ],
    description = "graph file size over time",
    deps = [
        "//code/programs/repo_tools/file_size_grapher:task_executer",
        "//code/programs/repo_tools/file_size_grapher/program_options:lib",
    ],
)
