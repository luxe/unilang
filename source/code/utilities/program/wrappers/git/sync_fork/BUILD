package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
hcp(
    name = "fork_syncer",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/git/repo_establisher:repo_location",
        "//code/utilities/program/wrappers/git/repo_establisher:repo_establisher",
        "//code/utilities/program/wrappers/git/repo_establisher:established_repo",
        "//code/utilities/filesystem/paths:lib",
    ],
)