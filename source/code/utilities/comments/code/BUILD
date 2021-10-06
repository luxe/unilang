package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "comment_creator",
    interface_deps = [
        "//code/utilities/comments/language:c_comment_settings",
        "//code/utilities/language_basic/relational_comparing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)
