package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "contributor_name")

hcp(
    name = "contributor_names",
    deps = [
        "contributor_name",
    ],
)
