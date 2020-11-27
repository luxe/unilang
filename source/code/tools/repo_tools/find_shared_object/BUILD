package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/tools/repo_tools/find_shared_object/program_options:lib",
        "//code/utilities/build/build_repo_establisher:build_repo_establisher",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
    ],
)

distributable_cpp_main(
    name = "find_shared_object",
    depends = [
    ],
    description = "find where a shared object is comming from via a particular bazel target",
    deps = [
        "//code/tools/repo_tools/find_shared_object:task_executer",
        "//code/tools/repo_tools/find_shared_object/program_options:lib",
    ],
)