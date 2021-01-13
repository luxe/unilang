package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "data_member_casing_settings",
    deps = ["//code/utilities/types/strings/transformers/casing:case_format_style"],
)

hcp(
    name = "data_member_options",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/comment:comment_settings",
        "//code/utilities/comments/doxygen/settings:doxygen_block_options",
        "//code/tools/transcompilers/old_unilang/options/sections:notation_settings",
        "//code/tools/transcompilers/old_unilang/options/sections/data_member:data_member_casing_settings",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
    ],
)
