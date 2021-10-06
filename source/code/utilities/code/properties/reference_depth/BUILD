package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "reference_depth_map",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "reference_depth_map_getter",
    interface_deps = [
        "//code/utilities/code/properties/reference_depth:fk_depth_calculator",
        "//code/utilities/code/properties/reference_depth:pk_depth_calculator",
        "//code/utilities/code/properties/reference_depth:reference_depth_map",
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/multimap:lib",
        "//code/utilities/types/tree:children_path_names",
        "//code/utilities/types/tree:parent_path",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
    ],
)

hcp_hdrs_derive(
    name = "default_reference_depth_map_getter",
    interface_deps = [
        "//code/utilities/code:concept_string_tree_getter",
        "//code/utilities/code/properties/reference_depth:reference_depth_map",
        "//code/utilities/code/properties/reference_depth:reference_depth_map_getter",
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/code/properties/references:reference_lookup_map_getter",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/multimap:lib",
        "//code/utilities/types/tree:children_path_names",
        "//code/utilities/types/tree:parent_path",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
    ],
)

hcp_hdrs_derive(
    name = "fk_depth_calculator",
    interface_deps = [
        "//code/utilities/code:concept_string_tree_getter",
        "//code/utilities/code/properties/reference_depth:reference_depth_map",
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/code/properties/references:reference_lookup_map_getter",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/multimap:lib",
        "//code/utilities/types/tree:children_path_names",
        "//code/utilities/types/tree:parent_path",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
    ],
)

hcp_hdrs_derive(
    name = "pk_depth_calculator",
    interface_deps = [
        "//code/utilities/code:concept_string_tree_getter",
        "//code/utilities/code/properties/reference_depth:reference_depth_map",
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/code/properties/references:reference_lookup_map_getter",
        "//code/utilities/output/printers:lib",
        "//code/utilities/types/multimap:lib",
        "//code/utilities/types/tree:children_path_names",
        "//code/utilities/types/tree:parent_path",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
    ],
)
