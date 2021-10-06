package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "comment_style",
    values = [
        "line",
        "block",
    ],
)

hcp_hdrs_derive(name = "c_line_comment_settings")

hcp_hdrs_derive(name = "c_block_comment_settings")

hcp_hdrs_derive(
    name = "c_comment_settings",
    interface_deps = [
        "//code/utilities/comments/language:c_block_comment_settings",
        "//code/utilities/comments/language:c_line_comment_settings",
        "//code/utilities/comments/language:comment_style",
    ],
)
