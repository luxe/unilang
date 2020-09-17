package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "color_palettes",
    deps = [
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "color_defaults",
    deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/position",
    ],
)

hcp(
    name = "rectangle_shades",
    deps = [
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_shade_colors",
        "//code/utilities/graphics/imgui:imgui_type_utility",
    ],
)
