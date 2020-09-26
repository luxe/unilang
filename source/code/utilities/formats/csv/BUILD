package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "csv_extractor",
    deps = [
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "@csv",
    ],
)
