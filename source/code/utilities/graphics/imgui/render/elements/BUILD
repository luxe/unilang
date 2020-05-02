package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="full_color_bitmap_drawer", deps = [
"//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:full_color_bitmap",
"//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:positioned_full_color_bitmap",
"//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
"//code/utilities/graphics/imgui/render/elements:pixel_drawer",
"//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
"//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
"//code/utilities/graphics/imgui:imgui_type_utility",
"//code/utilities/data_structures/position:position",
"//code/utilities/graphics/imgui:mechanics",
])

hcp(name="multi_color_bitmap_drawer", deps = [
"//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:multi_color_bitmap",
"//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
"//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
"//code/utilities/graphics/imgui/render/elements:pixel_drawer",
"//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
"//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
"//code/utilities/graphics/imgui:imgui_type_utility",
"//code/utilities/data_structures/position:position",
"//code/utilities/graphics/imgui:mechanics",
])

hcp(name="pixel_drawer", deps = [
"//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
"//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
"//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
"//code/utilities/graphics/imgui:imgui_type_utility",
"//code/utilities/data_structures/position:position",
"//code/utilities/graphics/imgui:mechanics",
])

hcp(name="line_drawer",deps = [
    "//code/utilities/data_structures/graphics/line:line_settings",
    "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
    "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
    "//code/utilities/graphics/imgui:imgui_type_utility",
    "//code/utilities/data_structures/position:position",
    "//code/utilities/graphics/imgui:mechanics",
])

hcp(name="rectangle_drawer", deps = [
    "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
    "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
    "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
    "//code/utilities/graphics/imgui:imgui_type_utility",
    "//code/utilities/data_structures/position:position",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
    "//code/utilities/data_structures/shapes/rectangle:shade_rectangle_settings",
    "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:multi_color_bitmap",
    "//code/utilities/colors:color_transitioner",
    "//code/utilities/graphics/imgui/render/elements:multi_color_bitmap_drawer",
    "//code/utilities/data_structures/graphics/rectangle:rectangle_fill_bitmap",
])
