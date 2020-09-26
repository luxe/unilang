package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "pluralization_pair")

hcp(
    name = "irregular_inflections",
    deps = [
        "pluralization_pair",
    ],
)
