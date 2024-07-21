package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "circle_draw_hooks",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "circle_fill_colors",
    interface_deps = ["//code/utilities/data_structures/color:transparent_rgb_color"],
)

hcp_hdrs_derive(
    name = "circle_settings",
    interface_deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/shapes/circle:circle_draw_hooks",
        "//code/utilities/data_structures/shapes/circle:circle_fill_colors",
    ],
)

hcp_hdrs_derive(
    name = "positioned_circle_settings",
    interface_deps = [
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/circle:circle_settings",
    ],
)
