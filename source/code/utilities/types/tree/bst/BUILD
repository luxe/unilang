package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "annotated_bst_fix", deps = [
    "//code/utilities/types/tree/bst:annotated_bst_state",
    "//code/utilities/types/tree:tree_traversal",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/types/tree:tree_node_properties",
    "//code/utilities/program/call:lib",
    "//code/utilities/types/char:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/tree/bst:annotated_bst_visualizer",
])

hcp(name = "annotated_bst_visualizer", deps = [
    "//code/utilities/types/tree/bst:annotated_bst_state",
    "//code/utilities/types/tree:tree_traversal",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/types/tree:tree_node_properties",
    "//code/utilities/program/call:lib",
    "//code/utilities/types/char:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/filesystem/files/deleting:lib",
    "//code/utilities/types/strings/creators:lib",
])

hcp(name = "annotated_bst_state", deps = [
    "//code/utilities/data_structures/tree:binary_node",
])

hcp(name = "prebuilt_bst_trees", deps = [
    "//code/utilities/data_structures/tree:binary_node",
    "//code/utilities/data_structures/tree:binary_nodes",
])