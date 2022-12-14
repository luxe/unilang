package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/programs/puzzles/advent_of_code/2022:task_executer"],
)

hcp_hdrs_derive(
    name = "task_executer",
    interface_deps = [
        "//code/programs/puzzles/advent_of_code:advent_of_code_input_getter",
        "//code/programs/puzzles/advent_of_code/2022:day_1",
        "//code/programs/puzzles/advent_of_code/2022:day_2",
        "//code/programs/puzzles/advent_of_code/2022:day_3",
        "//code/programs/puzzles/advent_of_code/2022:day_4",
        "//code/programs/puzzles/advent_of_code/2022:day_5",
        "//code/programs/puzzles/advent_of_code/2022:day_6",
        "//code/programs/puzzles/advent_of_code/2022:day_7",
        "//code/programs/puzzles/advent_of_code/2022:day_8",
        "//code/programs/puzzles/advent_of_code/2022:day_9",
        "//code/programs/puzzles/advent_of_code/2022:day_10",
        "//code/programs/puzzles/advent_of_code/2022:day_11",
        "//code/programs/puzzles/advent_of_code/2022:day_12",

    ],
)

hcp_hdrs_derive(
    name = "day_1",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)

hcp_hdrs_derive(
    name = "day_2",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
    ],
)

hcp_hdrs_derive(
    name = "day_3",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
    ],
)

hcp_hdrs_derive(
    name = "day_4",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
        "//code/utilities/types/range:create_range_from_string",
        "//code/utilities/types/range:interval_fully_contained_in_interval",
        "//code/utilities/types/range:intervals_overlap",
        "//code/utilities/formats/json/converters:type_to_json_string",
    ],
)

hcp_hdrs_derive(
    name = "day_5",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
        "//code/utilities/types/range:create_range_from_string",
        "//code/utilities/types/range:interval_fully_contained_in_interval",
        "//code/utilities/types/range:intervals_overlap",
        "//code/utilities/formats/json/converters:type_to_json_string",
    ],
)

hcp_hdrs_derive(
    name = "day_6",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/deps/stl/deque:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
        "//code/utilities/types/range:create_range_from_string",
        "//code/utilities/types/range:interval_fully_contained_in_interval",
        "//code/utilities/types/range:intervals_overlap",
        "//code/utilities/formats/json/converters:type_to_json_string",
    ],
)

hcp_hdrs_derive(
    name = "day_7",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/deps/stl/deque:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
        "//code/utilities/types/range:create_range_from_string",
        "//code/utilities/types/range:interval_fully_contained_in_interval",
        "//code/utilities/types/range:intervals_overlap",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/data_structures/tree/generic:string_int_tree",
        "//code/utilities/types/tree/printers:print_tree_as_json_blob_tree",
    ],
)

hcp_hdrs_derive(
    name = "day_8",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/deps/stl/deque:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
        "//code/utilities/types/range:create_range_from_string",
        "//code/utilities/types/range:interval_fully_contained_in_interval",
        "//code/utilities/types/range:intervals_overlap",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/data_structures/tree/generic:string_int_tree",
        "//code/utilities/types/tree/printers:print_tree_as_json_blob_tree",
        "//code/utilities/types/int_grid/creators:create_int_grid",
    ],
)

hcp_hdrs_derive(
    name = "day_9",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/deps/stl/deque:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
        "//code/utilities/types/range:create_range_from_string",
        "//code/utilities/types/range:interval_fully_contained_in_interval",
        "//code/utilities/types/range:intervals_overlap",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/data_structures/tree/generic:string_int_tree",
        "//code/utilities/types/tree/printers:print_tree_as_json_blob_tree",
        "//code/utilities/data_structures/compass_directions/creators:compass_direction_diagnonal_movements_creator",
        "//code/utilities/data_structures/position:position_mover",
        "//code/utilities/data_structures/position:all_positions_along_movement",
        "//code/utilities/types/vectors/transformers:remove_duplicate_json_representations",
    ],
)

hcp_hdrs_derive(
    name = "day_10",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/deps/stl/deque:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
        "//code/utilities/types/range:create_range_from_string",
        "//code/utilities/types/range:interval_fully_contained_in_interval",
        "//code/utilities/types/range:intervals_overlap",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/data_structures/tree/generic:string_int_tree",
        "//code/utilities/types/tree/printers:print_tree_as_json_blob_tree",
    ],
)

hcp_hdrs_derive(
    name = "day_11",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/deps/stl/deque:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
        "//code/utilities/types/range:create_range_from_string",
        "//code/utilities/types/range:interval_fully_contained_in_interval",
        "//code/utilities/types/range:intervals_overlap",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/data_structures/tree/generic:string_int_tree",
        "//code/utilities/types/tree/printers:print_tree_as_json_blob_tree",
    ],
)

hcp_hdrs_derive(
    name = "day_12",
    interface_deps = [
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/unordered_set:lib",
        "//code/utilities/deps/stl/map:lib",
        "//code/utilities/deps/stl/deque:lib",
        "//code/utilities/data_structures:rock_paper_scissors_move",
        "//code/utilities/types/range:create_range_from_string",
        "//code/utilities/types/range:interval_fully_contained_in_interval",
        "//code/utilities/types/range:intervals_overlap",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/data_structures/tree/generic:string_int_tree",
        "//code/utilities/types/tree/printers:print_tree_as_json_blob_tree",
    ],
)