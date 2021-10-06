package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "rgb_color",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "rgb_color_transition",
    interface_deps = ["//code/utilities/data_structures/color:rgb_color"],
)

hcp_hdrs_derive(
    name = "rgba_color_transition",
    interface_deps = ["//code/utilities/data_structures/color:transparent_rgb_color"],
)

hcp_hdrs_derive(
    name = "rgb_part_range",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "rgb_parts_ranges",
    interface_deps = ["//code/utilities/data_structures/color:rgb_part_range"],
)

hcp_hdrs_derive(
    name = "transparent_rgb_color",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "hsv_color",
    interface_deps = [],
)

hcp_hdrs_derive(
    name = "transparent_hsv_color",
    interface_deps = [],
)
