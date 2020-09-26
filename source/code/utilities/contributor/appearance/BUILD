package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object("gender")

cpp_object("species")

hcp(
    name = "contributor_appearance",
    deps = [
        "//code/utilities/contributor/appearance:gender",
        "//code/utilities/contributor/appearance:species",
    ],
)
