package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:gtest.bzl", "gtest")

cpp_object(
    name = "depth_list",
    deps = [
        "//code/utilities/deps/external/tree:lib",
    ],
)

hcp(
    name = "tree_full_paths_getter",
    deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/tree:full_path_name",
        "//code/utilities/types/tree/bst:annotated_bst_state",
        "//code/utilities/types/tree/bst:annotated_bst_visualizer",
        "//code/utilities/types/tree/bst:tree_node_properties",
        "//code/utilities/types/tree/bst:tree_traversal",
    ],
)

hcp(
    name = "path_to_iterator",
    deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/types/tree:full_path_name",
    ],
)
