package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "typedef_options",
    deps = [
        "//code/tools/transcompilers/unilang/options/comment:comment_settings",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
    ],
)
