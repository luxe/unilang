package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "data_member_casing_settings",
    deps = ["//code/utilities/types/strings/transformers/casing:case_format_style"],
)

hcp(
    name = "data_member_options",
    deps = [
        "//code/utilities/comments/code/settings:comment_settings",
        "//code/utilities/comments/doxygen/settings:doxygen_block_options",
        "//code/utilities/linguistics/computer/frontends/parts:notation_settings",
        "//code/utilities/linguistics/computer/frontends/parts/data_member:data_member_casing_settings",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
    ],
)
