package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "html_table_options",
    deps = [
        "//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
    ],
)
