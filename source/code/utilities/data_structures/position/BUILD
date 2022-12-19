package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(name = "position")

hcp_hdrs_derive(
    name = "position_mover",
    interface_deps = [
        "//code/utilities/data_structures:compass_direction",
        "//code/utilities/data_structures:compass_direction_diagnonal",
        "//code/utilities/data_structures/compass_directions:compass_direction_diagnonal_movement",
        "//code/utilities/data_structures/compass_directions:compass_direction_diagnonal_movements",
        "//code/utilities/data_structures/position",
    ],
)

hcp_hdrs_derive(
    name = "all_positions_along_movement",
    interface_deps = [
        "//code/utilities/data_structures:compass_direction",
        "//code/utilities/data_structures:compass_direction_diagnonal",
        "//code/utilities/data_structures/compass_directions:compass_direction_diagnonal_movement",
        "//code/utilities/data_structures/compass_directions:compass_direction_diagnonal_movements",
        "//code/utilities/data_structures/position:position_mover",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
