package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "standard_javadoc_style_lines")

hcp(name = "standard_qt_style_lines")

hcp(name = "standard_slash_bang_style_lines")

hcp(name = "standard_triple_slash_style_lines")

hcp(name = "standard_double_slash_style_lines")

hcp(
    name = "standard_doxygen_style_lines",
    deps = [
        "standard_double_slash_style_lines",
        "standard_javadoc_style_lines",
        "standard_qt_style_lines",
        "standard_slash_bang_style_lines",
        "standard_triple_slash_style_lines",
    ],
)
