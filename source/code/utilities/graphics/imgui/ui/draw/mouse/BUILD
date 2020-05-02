package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="mouse", deps = [
    "//code/utilities/graphics/imgui/ui/draw/mouse:mouse_selection",
    "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
])

hcp(name="mouse_selection",deps = [
    "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
])

hcp(name="cursor_mouse_connector",deps = [
    "//code/utilities/data_structures/graphics/line:line_settings",
])

hcp(name="anchor_mouse",deps = [
    "//code/utilities/graphics/imgui/ui/draw/mouse:mouse",
    "//code/utilities/data_structures/position:position",
])