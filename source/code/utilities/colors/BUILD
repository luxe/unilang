package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
)

hcp(
    name = "hsv_to_rgb_converter",
    deps = [
        "//code/utilities/data_structures/color:hsv_color",
        "//code/utilities/data_structures/color:rgb_color",
    ],
)

hcp(
    name = "color_transitioner",
    deps = [
        "//code/utilities/data_structures/color:rgb_color_transition",
        "//code/utilities/data_structures/color:rgba_color_transition",
    ],
)

hcp(
    name = "color_palettes",
    deps = [
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "rectangle_shades",
    deps = [
        "//code/utilities/colors:color_defaults",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_shade_colors",
        "//code/utilities/graphics/imgui:imgui_type_utility",
    ],
)

hcp(
    name = "converters",
    deps = [
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "@sfml",
    ],
)

hcp(
    name = "screen_position_to_rgb",
    deps = [
        "//code/utilities/colors:hsv_to_rgb_converter",
        "//code/utilities/data_structures/color:hsv_color",
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/data_structures/position",
        "//code/utilities/math",
    ],
)

hcp(
    name = "sfml_color_pick_grid",
    deps = [
        "@sfml",
    ],
)

hcp(
    name = "sfml_color_pick_hue_changer",
    deps = [
        "@sfml",
    ],
)

hcp(
    name = "color_defaults",
    deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/position",
    ],
)
