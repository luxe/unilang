package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(name = "point")

hcp_hdrs_derive(
    name = "point_line",
    interface_deps = [
        "//code/utilities/data_structures/point",
    ],
)

hcp_hdrs_derive(
    name = "directional_point",
    interface_deps = [
        "//code/utilities/data_structures:compass_direction_diagnonal",
        "//code/utilities/data_structures/point",
    ],
)

hcp_hdrs_derive(
    name = "point_mover",
    interface_deps = [
        "//code/utilities/data_structures:compass_direction",
        "//code/utilities/data_structures:compass_direction_diagnonal",
        "//code/utilities/data_structures/compass_directions:compass_direction_diagnonal_movement",
        "//code/utilities/data_structures/compass_directions:compass_direction_diagnonal_movements",
        "//code/utilities/data_structures/point",
    ],
)

hcp_hdrs_derive(
    name = "point_range_checker",
    interface_deps = [
        "//code/utilities/data_structures/point",
        "//code/utilities/language_basic/std_hackery:std_aliases",
    ],
)

hcp_hdrs_derive(
    name = "point_line_intersections_getter",
    interface_deps = [
        "//code/utilities/data_structures/point",
        "//code/utilities/data_structures/point:point_line",
        "//code/utilities/data_structures/point:point_line_to_points",
    ],
)

hcp_hdrs_derive(
    name = "point_line_to_points",
    interface_deps = [
        "//code/utilities/data_structures/point",
        "//code/utilities/data_structures/point:point_line",
    ],
)
