package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "repo_location", deps = [
])

hcp(name = "repo_establisher", deps = [
    "//code/utilities/shell:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/git-related:lib",
    "//code/utilities/git-related/repo_establisher:repo_location",
    "//code/utilities/random:lib",
    "//code/utilities/filesystem/files/moving:lib",
])