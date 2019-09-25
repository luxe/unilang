package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="rectangle_draw_hooks",deps = [])
hcp(name="rectangle_dimensions",deps = [])
hcp(name="rectangle_edge",deps = [])
hcp(name="rectangle_settings",deps = [
    "//code/utilities/data_structures/color:transparent_rgb_color",
    "//code/utilities/data_structures/shapes/rectangle:rectangle_draw_hooks",
    "//code/utilities/data_structures/shapes/rectangle:rectangle_dimensions",
    "//code/utilities/data_structures/shapes/rectangle:rectangle_edge",
])

hcp(name="positioned_rectangle_settings",deps = [
    "//code/utilities/data_structures/position:position",
    "//code/utilities/data_structures/shapes/rectangle:rectangle_settings"
])