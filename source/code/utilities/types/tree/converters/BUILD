package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:gtest.bzl", "gtest")


cpp_object(name = "depth_list",deps=[
    "@tree//:tree"
])

hcp(name = "tree_full_paths_getter", deps = [
    "//code/utilities/types/tree/bst:annotated_bst_state",
    "//code/utilities/types/tree/bst:tree_traversal",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/types/tree/bst:tree_node_properties",
    "//code/utilities/program/call:lib",
    "//code/utilities/types/char:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/tree/bst:annotated_bst_visualizer",
    "//code/utilities/data_structures/tree/generic:string_tree",
])