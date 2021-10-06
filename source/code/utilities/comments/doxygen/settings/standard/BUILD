package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(name = "standard_javadoc_style_lines")

hcp_hdrs_derive(name = "standard_qt_style_lines")

hcp_hdrs_derive(name = "standard_slash_bang_style_lines")

hcp_hdrs_derive(name = "standard_triple_slash_style_lines")

hcp_hdrs_derive(name = "standard_double_slash_style_lines")

hcp_hdrs_derive(
    name = "standard_doxygen_style_lines",
    interface_deps = [
        "//code/utilities/comments/doxygen/settings/standard:standard_double_slash_style_lines",
        "//code/utilities/comments/doxygen/settings/standard:standard_javadoc_style_lines",
        "//code/utilities/comments/doxygen/settings/standard:standard_qt_style_lines",
        "//code/utilities/comments/doxygen/settings/standard:standard_slash_bang_style_lines",
        "//code/utilities/comments/doxygen/settings/standard:standard_triple_slash_style_lines",
    ],
)
