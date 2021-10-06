package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:gtest.bzl", "gtest")

hcp(
    name = "str_tree_to_unique_id_tree",
    deps = [
        "//code/utilities/code:concept_string_tree_getter",
        "//code/utilities/code/artifacts/split_concept_tree/data:split_string_trees",
        "//code/utilities/code/properties/reference_depth:reference_depth_map",
        "//code/utilities/code/properties/reference_depth:reference_depth_map_getter",
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/code/properties/references:reference_lookup_map_getter",
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/multimap:lib",
        "//code/utilities/types/tree:children_path_names",
        "//code/utilities/types/tree:parent_path",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
    ],
)

hcp(
    name = "unique_id_tree_to_str_tree",
    deps = [
        "//code/utilities/code:concept_string_tree_getter",
        "//code/utilities/code/artifacts/split_concept_tree/data:split_string_trees",
        "//code/utilities/code/properties/reference_depth:reference_depth_map",
        "//code/utilities/code/properties/reference_depth:reference_depth_map_getter",
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/code/properties/references:reference_lookup_map_getter",
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/multimap:lib",
        "//code/utilities/types/tree:children_path_names",
        "//code/utilities/types/tree:parent_path",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
    ],
)
