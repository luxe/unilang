package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:gtest.bzl", "gtest")

hcp(name = "annotated_bst_fix", deps = [
    "//code/utilities/types/tree/bst:annotated_bst_state",
    "//code/utilities/types/tree/bst:tree_traversal",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/types/tree/bst:tree_node_properties",
    "//code/utilities/program/call:lib",
    "//code/utilities/types/char:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/tree/bst:annotated_bst_visualizer",
])

hcp(name = "annotated_bst_visualizer", deps = [
    "//code/utilities/types/tree/bst:annotated_bst_state",
    "//code/utilities/types/tree/bst:tree_traversal",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/types/tree/bst:tree_node_properties",
    "//code/utilities/program/call:lib",
    "//code/utilities/types/char:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/filesystem/files/deleting:lib",
    "//code/utilities/types/strings/creators:lib",
])

hcp(name = "annotated_bst_state", deps = [
    "//code/utilities/data_structures/tree/bst:binary_node",
])

hcp(name = "prebuilt_bst_trees", deps = [
    "//code/utilities/data_structures/tree/bst:binary_node",
    "//code/utilities/data_structures/tree/bst:binary_nodes",
])

hcp(name = "tree_traversal",deps=[
"//code/utilities/data_structures/tree/bst:binary_node",
"//code/utilities/types/tree/bst:tree_node_properties",
"//code/utilities/data_structures/tree/bst:binary_node_with_height",
])

hcp(name = "tree_node_properties",deps=[
"//code/utilities/data_structures/tree/bst:binary_node",
])


gtest(
    name = "tree_traversal_test",
    deps = [
        "//code/utilities/types/tree/bst:tree_traversal",
        "//code/utilities/data_structures/tree/bst:binary_node",
        "//code/utilities/types/tree/bst:annotated_bst_fix",
        "//code/utilities/types/tree/bst:annotated_bst_state",
        "//code/utilities/data_structures/tree/bst:binary_nodes",
        "//code/utilities/types/tree/bst:prebuilt_bst_trees",
        "//code/tools/hackerrank:bst_swap_solution_geeks_five_ptrs",
    ]
)
