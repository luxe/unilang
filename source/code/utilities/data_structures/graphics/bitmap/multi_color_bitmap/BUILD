package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp(
    name = "multi_color_bitmap",
    deps = [
        "//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
    ],
)

hcp_and_hcp_pos(
    name = "multi_color_bitmap_button",
    deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
    ],
)

hcp(
    name = "positioned_multi_color_bitmap",
    deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/position",
    ],
)
