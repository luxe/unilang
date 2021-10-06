package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "color_palettes",
    interface_deps = [
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp_hdrs_derive(
    name = "color_defaults",
    interface_deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/position",
    ],
)

hcp_hdrs_derive(
    name = "rectangle_shades",
    interface_deps = [
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_shade_colors",
        "//code/utilities/graphics/imgui:imgui_type_utility",
    ],
)
