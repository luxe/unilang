package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "doxygen_block_style",
    values = [
        "JAVADOC",
        "QT",
        "TRIPLE_SLASH",
        "DOUBLE_SLASH",
        "SLASH_BANG",
    ],
)

enum_cpp(
    name = "doxygen_parameter_direction",
    values = [
        "IN",
        "OUT",
        "IN_OUT",
    ],
)

hcp_hdrs_derive(
    name = "doxygen_block_options",
    interface_deps = [
        "//code/utilities/comments/doxygen/settings:doxygen_block_style",
        "//code/utilities/comments/doxygen/settings/standard:standard_doxygen_style_lines",
    ],
)
