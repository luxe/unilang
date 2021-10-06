package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")

hcp_and_hcp_pos_hdrs_derive(
    name = "buttoned_faced_label",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:multi_color_bitmap_button",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap_button",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label_style",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
    ],
)

hcp_hdrs_derive(
    name = "buttoned_faced_label_style",
    interface_deps = [
    ],
)
