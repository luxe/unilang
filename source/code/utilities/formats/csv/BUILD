package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "csv_extractor",
    interface_deps = [
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/deps/external/csv:lib",
    ],
)
