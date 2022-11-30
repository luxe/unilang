package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "change_connected_values",
    interface_deps = [
            "//code/utilities/language_basic/std_hackery:std_aliases",
            "//code/utilities/deps/stl/queue:lib",
            "//code/utilities/types/queue:lib",
            "//code/utilities/data_structures/position:position",
            "//code/utilities/formats/json/converters:type_to_json_string",
            "//code/utilities/formats/json/converters:lib",
            "//code/utilities/types/int_grid:get_valid_neighbors",
    ],
)

hcp_hdrs_derive(
    name = "count_connected_values",
    interface_deps = [
            "//code/utilities/language_basic/std_hackery:std_aliases",
            "//code/utilities/deps/stl/queue:lib",
            "//code/utilities/types/queue:lib",
            "//code/utilities/data_structures/position:position",
            "//code/utilities/formats/json/converters:type_to_json_string",
            "//code/utilities/formats/json/converters:lib",
            "//code/utilities/types/int_grid:get_valid_neighbors",
    ],
)

hcp_hdrs_derive(
    name = "get_valid_neighbors",
    interface_deps = [
            "//code/utilities/language_basic/std_hackery:std_aliases",
            "//code/utilities/data_structures/position:position",
    ],
)


# positions
hcp_hdrs_derive(
    name = "lower_left",
    interface_deps = [
            "//code/utilities/language_basic/std_hackery:std_aliases",
            "//code/utilities/data_structures/position:position",
    ],
)

hcp_hdrs_derive(
    name = "upper_right",
    interface_deps = [
            "//code/utilities/language_basic/std_hackery:std_aliases",
            "//code/utilities/data_structures/position:position",
    ],
)
