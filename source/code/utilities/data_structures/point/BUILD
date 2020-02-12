package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "point")
hcp(name = "point_line", deps = [
    "//code/utilities/data_structures/point:point",
])
hcp(name = "directional_point", deps = [
    "//code/utilities/data_structures/point:point",
    "//code/utilities/data_structures:compass_direction_diagnonal",
])


hcp(name = "point_mover", deps = [
    "//code/utilities/data_structures:compass_direction",
    "//code/utilities/data_structures:compass_direction_diagnonal",
    "//code/utilities/data_structures/point:point",
    "//code/utilities/data_structures/compass_directions:compass_direction_diagnonal_movement",
])

hcp(name = "point_range_checker", deps = [
    "//code/utilities/language_basic/std_hackery:std_aliases",
    "//code/utilities/data_structures/point:point",
])

hcp(name = "point_line_intersections_getter", deps = [
    "//code/utilities/data_structures/point:point",
    "//code/utilities/data_structures/point:point_line",
    "//code/utilities/data_structures/point:point_line_to_points",
])

hcp(name = "point_line_to_points", deps = [
    "//code/utilities/data_structures/point:point",
    "//code/utilities/data_structures/point:point_line",
])