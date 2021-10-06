package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "comment_style_category",
    values = [
        "language",
        "doxygen",
    ],
)

hcp_hdrs_derive(
    name = "comment_settings",
    interface_deps = [
        "//code/utilities/comments/code/settings:comment_style_category",
        "//code/utilities/comments/doxygen/settings:doxygen_block_options",
        "//code/utilities/comments/language:c_comment_settings",
        "//code/utilities/linguistics/grammar/settings:comment_grammar_settings",
        "//code/utilities/types/strings/observers/reflow/settings:comment_reflow_settings",
    ],
)
