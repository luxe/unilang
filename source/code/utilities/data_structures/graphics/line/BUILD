package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="line_settings",deps = [
    "//code/utilities/data_structures/color:transparent_rgb_color",
    "//code/utilities/data_structures/position:position"
])


hcp(name="line_drawer",deps = [
    "//code/utilities/data_structures/graphics/line:line_settings",
    "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
    "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
    "//code/utilities/graphics/imgui/draw:imgui_type_utility",
    "//code/utilities/data_structures/position:position",
    "//code/utilities/graphics/imgui:mechanics",
])