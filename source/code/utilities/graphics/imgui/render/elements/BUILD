package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "full_color_bitmap_drawer",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:positioned_full_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/position",
        "//code/utilities/graphics/imgui:imgui_type_utility",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/graphics/imgui/render/elements:pixel_drawer",
    ],
)

hcp_hdrs_derive(
    name = "multi_color_bitmap_drawer",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/position",
        "//code/utilities/graphics/imgui:imgui_type_utility",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/graphics/imgui/render/elements:pixel_drawer",
    ],
)

hcp_hdrs_derive(
    name = "pixel_drawer",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/position",
        "//code/utilities/graphics/imgui:imgui_type_utility",
        "//code/utilities/graphics/imgui/loop:mechanics",
    ],
)

hcp_hdrs_derive(
    name = "line_drawer",
    interface_deps = [
        "//code/utilities/data_structures/graphics/line:line_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/position",
        "//code/utilities/graphics/imgui:imgui_type_utility",
        "//code/utilities/graphics/imgui/loop:mechanics",
    ],
)

hcp_hdrs_derive(
    name = "rectangle_drawer",
    interface_deps = [
        "//code/utilities/colors/transformers:color_transitioner",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/graphics/rectangle:rectangle_fill_bitmap",
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
        "//code/utilities/data_structures/shapes/rectangle:shade_rectangle_settings",
        "//code/utilities/graphics/imgui:imgui_type_utility",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/graphics/imgui/render/elements:multi_color_bitmap_drawer",
    ],
)

hcp_hdrs_derive(
    name = "circle_drawer",
    interface_deps = [
        "//code/utilities/colors/transformers:color_transitioner",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/circle:positioned_circle_settings",
        "//code/utilities/data_structures/shapes/circle:circle_settings",
        "//code/utilities/graphics/imgui:imgui_type_utility",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/graphics/imgui/render/elements:multi_color_bitmap_drawer",
    ],
)
