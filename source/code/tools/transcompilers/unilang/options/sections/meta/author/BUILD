package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(
    name = "author_order_method",
)

cpp_object(
    name = "meta_author_print_method",
)

hcp(
    name = "meta_author_tag_options",
    deps = [
        "author_order_method",
        "meta_author_print_method",
        "//code/tools/transcompilers/unilang/options/sections/meta/other:meta_tag_existence_option",
    ],
)
