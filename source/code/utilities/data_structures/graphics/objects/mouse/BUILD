package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "mouse",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/objects/mouse:mouse_selection",
    ],
)

hcp_hdrs_derive(
    name = "mouse_selection",
    interface_deps = [
        "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
    ],
)

hcp_hdrs_derive(
    name = "cursor_mouse_connector",
    interface_deps = [
        "//code/utilities/data_structures/graphics/line:line_settings",
    ],
)

hcp_hdrs_derive(
    name = "anchor_mouse",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/mouse",
        "//code/utilities/data_structures/position",
    ],
)
