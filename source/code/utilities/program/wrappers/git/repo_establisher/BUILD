package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "repo_location", deps = [])

hcp(name = "repo_establisher", deps = [
    "//code/utilities/program/call:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/program/wrappers/git:lib",
    "//code/utilities/program/wrappers/git/repo_establisher:repo_location",
    "//code/utilities/random:lib",
    "//code/utilities/filesystem/files/moving:lib",
    "//code/utilities/program/wrappers/git/repo_establisher:established_repo",
])

hcp(name = "established_repo", deps = [])