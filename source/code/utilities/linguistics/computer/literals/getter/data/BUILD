package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "literal_suffix_settings",
    deps = [
        "floating_point_literal_settings",
    ],
)

hcp(name = "floating_point_literal_settings")
