package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "rectangle_fill_bitmap",
    deps = [
        "//code/utilities/colors:color_transitioner",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
        "//code/utilities/data_structures/shapes/rectangle:shade_rectangle_settings",
        "//code/utilities/graphics/imgui:imgui_type_utility",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/graphics/imgui/render/elements:multi_color_bitmap_drawer",
    ],
)
