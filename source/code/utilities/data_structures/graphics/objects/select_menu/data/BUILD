package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")

hcp_and_hcp_pos_hdrs_derive(
    name = "select_menu",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_tree:face_tree",
        "//code/utilities/data_structures/graphics/objects/select_menu/data:select_menu_control_settings",
    ],
)

hcp_hdrs_derive(
    name = "select_menu_control_settings",
    interface_deps = [
    ],
)
