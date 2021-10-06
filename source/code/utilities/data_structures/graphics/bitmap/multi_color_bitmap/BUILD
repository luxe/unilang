package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")

hcp_hdrs_derive(
    name = "multi_color_bitmap",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
    ],
)

hcp_and_hcp_pos_hdrs_derive(
    name = "multi_color_bitmap_button",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
    ],
)

hcp_hdrs_derive(
    name = "positioned_multi_color_bitmap",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/position",
    ],
)
