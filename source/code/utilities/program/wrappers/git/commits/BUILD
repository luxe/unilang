package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "git_all_commits_getter",
    interface_deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/git/repo_establisher",
        "//code/utilities/program/wrappers/git/repo_establisher:established_repo",
        "//code/utilities/program/wrappers/git/repo_establisher:repo_location",
        "//code/utilities/program/wrappers/git/commits:git_all_commits",
    ],
)

hcp_hdrs_derive(
    name = "git_all_commits",
    interface_deps = [
        "//code/utilities/program/call:lib",
    ],
)
