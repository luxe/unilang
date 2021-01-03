package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")


hcp(
    name = "essay_publisher",
    deps = [
        "//code/utilities/output/publisher/essay:essay",
        "//code/utilities/output/publisher/essay/specific:clean_site_essay_publisher",
        "//code/utilities/output/publisher/essay/specific:latex_essay_publisher",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/code:concept_static_tree_structs",
    ],
)

hcp(
    name = "essay",
    deps = [
        "//code/utilities/output/publisher/essay:essay_style",
    ],
)

enum_cpp(
    name = "essay_style",
    values = [
        "scientific",
        "poetic",
    ],
)