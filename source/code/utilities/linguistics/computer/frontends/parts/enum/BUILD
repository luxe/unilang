package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "when_to_show_empty_enum_comment")

cpp_object(name = "enum_utility_values_placement")

hcp(name = "enum_utility_value_option")

hcp(
    name = "enum_utility_values_options",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/enum:enum_utility_value_option",
        "//code/utilities/linguistics/computer/frontends/parts/enum:enum_utility_values_placement",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
    ],
)

hcp(
    name = "enum_options",
    deps = [
        "//code/utilities/comments/code/settings:comment_settings",
        "//code/utilities/comments/doxygen/settings:doxygen_block_options",
        "//code/utilities/linguistics/computer/frontends/parts/enum:enum_utility_values_options",
        "//code/utilities/linguistics/computer/frontends/parts/enum:when_to_show_empty_enum_comment",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
    ],
)
