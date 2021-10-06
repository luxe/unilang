package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "crosshair_mouse",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
    ],
)

hcp_hdrs_derive(
    name = "tree_expand_symbol",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
    ],
)

hcp_hdrs_derive(
    name = "tree_collapse_symbol",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
    ],
)

hcp_hdrs_derive(
    name = "tree_button",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:multi_color_bitmap_button",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap_button",
        "//code/utilities/data_structures/graphics/bitmap/premade:tree_collapse_symbol",
        "//code/utilities/data_structures/graphics/bitmap/premade:tree_expand_symbol",
    ],
)

hcp_hdrs_derive(
    name = "vertical_line",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
    ],
)

hcp_hdrs_derive(
    name = "horizontal_line",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
    ],
)

hcp_hdrs_derive(
    name = "l_line",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
    ],
)

hcp_hdrs_derive(
    name = "right_arrow",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
    ],
)

hcp_hdrs_derive(
    name = "left_arrow",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
    ],
)
