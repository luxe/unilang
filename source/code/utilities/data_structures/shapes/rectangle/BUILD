package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "rectangle_draw_hooks",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "rectangle_dimensions",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "rectangle_edge",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "rectangle_fill_colors",
    interface_deps = ["//code/utilities/data_structures/color:transparent_rgb_color"],
)

hcp_hdrs_derive(
    name = "rectangle_shade_colors",
    interface_deps = [
        "//code/utilities/data_structures/color:rgba_color_transition",
        "//code/utilities/data_structures/color:transparent_rgb_color",
    ],
)

hcp_hdrs_derive(
    name = "rectangle_settings",
    interface_deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_dimensions",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_draw_hooks",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_edge",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_fill_colors",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_shade_colors",
    ],
)

hcp_hdrs_derive(
    name = "shade_rectangle_settings",
    interface_deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_dimensions",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_draw_hooks",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_edge",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_shade_colors",
    ],
)

hcp_hdrs_derive(
    name = "positioned_rectangle_settings",
    interface_deps = [
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
    ],
)
