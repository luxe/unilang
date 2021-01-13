package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "doxygen_block_style")

cpp_object(name = "doxygen_parameter_direction")

hcp(
    name = "doxygen_block_options",
    deps = [
        "//code/utilities/comments/doxygen/settings:doxygen_block_style",
        "//code/utilities/comments/doxygen/settings/standard:standard_doxygen_style_lines",
    ],
)
