package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "all_argument_attribute_placements",
    deps = ["argument_attribute_placement"],
)

hcp(
    name = "all_method_attribute_placements",
    deps = ["method_attribute_placement"],
)

hcp(name = "argument_attribute_placement")

hcp(name = "method_attribute_placement")
