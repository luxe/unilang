package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "color_transitioner",
    interface_deps = [
        "//code/utilities/data_structures/color:rgb_color_transition",
        "//code/utilities/data_structures/color:rgba_color_transition",
    ],
)

hcp_hdrs_derive(
    name = "color_shader",
    interface_deps = [
        "//code/utilities/colors/transformers:color_clamp",
        "//code/utilities/data_structures/color:rgb_color_transition",
        "//code/utilities/data_structures/color:rgba_color_transition",
        "//code/utilities/data_structures/color:transparent_rgb_color",
    ],
)

hcp_hdrs_derive(
    name = "color_tinter",
    interface_deps = [
        "//code/utilities/data_structures/color:rgb_color_transition",
        "//code/utilities/data_structures/color:rgba_color_transition",
    ],
)

hcp_hdrs_derive(
    name = "screen_position_to_rgb",
    interface_deps = [
        "//code/utilities/colors/converters:hsv_to_rgb_converter",
        "//code/utilities/data_structures/color:hsv_color",
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/data_structures/position",
        "//code/utilities/math",
    ],
)

hcp_hdrs_derive(
    name = "color_clamp",
    interface_deps = [
        "//code/utilities/colors/converters:hsv_to_rgb_converter",
        "//code/utilities/data_structures/color:hsv_color",
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/position",
        "//code/utilities/math",
    ],
)
