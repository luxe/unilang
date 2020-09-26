package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "mouse",
    deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/objects/mouse:mouse_selection",
    ],
)

hcp(
    name = "mouse_selection",
    deps = [
        "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
    ],
)

hcp(
    name = "cursor_mouse_connector",
    deps = [
        "//code/utilities/data_structures/graphics/line:line_settings",
    ],
)

hcp(
    name = "anchor_mouse",
    deps = [
        "//code/utilities/data_structures/graphics/objects/mouse",
        "//code/utilities/data_structures/position",
    ],
)
