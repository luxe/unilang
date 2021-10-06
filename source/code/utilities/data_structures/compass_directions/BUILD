package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "compass_direction_diagnonal_movement",
    interface_deps = [
        "//code/utilities/data_structures:compass_direction_diagnonal",
    ],
)

hcp_hdrs_derive(
    name = "compass_direction_diagnonal_movements",
    interface_deps = [
        "//code/utilities/data_structures/compass_directions:compass_direction_diagnonal_movement",
    ],
)
