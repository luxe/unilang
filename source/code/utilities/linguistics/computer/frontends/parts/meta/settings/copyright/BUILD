package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(
    name = "meta_copyright_print_method",
)

hcp(
    name = "meta_copyright_tag_options",
    deps = ["meta_copyright_print_method"],
)
