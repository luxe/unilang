package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="full_color_bitmap_drawer", deps = [
"//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:full_color_bitmap",
"//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:positioned_full_color_bitmap",
"//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
"//code/utilities/graphics/imgui/render/elements:pixel_drawer",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
"//code/utilities/graphics/imgui/ui/draw:imgui_type_utility",
"//code/utilities/data_structures/position:position",
"//code/utilities/graphics/imgui:mechanics",
])

hcp(name="multi_color_bitmap_drawer", deps = [
"//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:multi_color_bitmap",
"//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
"//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
"//code/utilities/graphics/imgui/render/elements:pixel_drawer",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
"//code/utilities/graphics/imgui/ui/draw:imgui_type_utility",
"//code/utilities/data_structures/position:position",
"//code/utilities/graphics/imgui:mechanics",
])

hcp(name="pixel_drawer", deps = [
"//code/utilities/data_structures/graphics/bitmap/pixel:pixel_settings",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
"//code/utilities/graphics/imgui/ui/draw:imgui_type_utility",
"//code/utilities/data_structures/position:position",
"//code/utilities/graphics/imgui:mechanics",
])