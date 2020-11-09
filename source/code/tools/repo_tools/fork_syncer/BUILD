package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

distributable_cpp_main(
    name = "fork_syncer",
    depends = [
    ],
    description = "sync a fork with the original upstream",
    deps = [
        "//code/utilities/program/wrappers/git/sync_fork:fork_syncer"
    ],
)