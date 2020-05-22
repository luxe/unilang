package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/github:orgs_repo_getter",
        "//code/utilities/github:repo_deleter",
        "//code/utilities/github:user_forked_repos_getter",
        "//code/utilities/program/call:lib",
    ],
)
