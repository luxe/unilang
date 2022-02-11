package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")

hcp_and_hcp_pos_hdrs_derive(
    name = "interactive_retangle",
    interface_deps = [
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
    ],
)
