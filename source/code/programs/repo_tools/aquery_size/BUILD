package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/programs/repo_tools/aquery_size/program_options:lib",
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
    ],
)


# Program purpose:
# Sometimes intermediate files are so large that they can't be uploaded to remote execution / caching systems.
# The implicit limitation seems to be ~2GB due to a serialized protobuf limit.
# Finding these large files is not obvious because they might be outputs generated from an action.
# The trick is to do a build, and then run aquery on a target and analyze the files to find the offenders.
distributable_cpp_main(
    name = "aquery_size",
    depends = [
    ],
    description = "find sizes of files from aquery",
    deps = [
        "//code/programs/repo_tools/aquery_size:task_executer",
        "//code/programs/repo_tools/aquery_size/program_options:lib",
    ],
)
