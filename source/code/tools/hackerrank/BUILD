package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/cpp:gtest.bzl", "gtest")
load("//bazel/cookbook/hcp:main.bzl", "hcp")

gtest(
    name = "bst_swap_test",
    deps = [
        "//code/tools/hackerrank:bst_swap_solution_sliding_window_two_ptrs",
        "//code/tools/hackerrank:bst_swap_solution_in_out",
        "//code/utilities/types/tree:tree_traversal",
    ]
)

cc_library(
    name = "bst_swap_solution",
    hdrs = ["bst_swap_solution.hpp"],
    deps = [
        "//code/utilities/printers:lib",
        "//code/utilities/data_structures/tree:binary_node",
        "//code/utilities/types/tree:tree_traversal",
        "//code/utilities/types/tree:tree_node_properties",
    ]
)

hcp(name = "bst_swap_solution_sliding_window_two_ptrs", deps = [
    "//code/utilities/printers:lib",
    "//code/utilities/data_structures/tree:binary_node",
    "//code/utilities/types/tree:tree_traversal",
    "//code/utilities/types/tree:tree_node_properties",
])

hcp(name = "bst_swap_solution_in_out", deps = [
    "//code/utilities/printers:lib",
    "//code/utilities/data_structures/tree:binary_node",
    "//code/utilities/types/tree:tree_traversal",
    "//code/utilities/types/tree:tree_node_properties",
])

hcp(name = "bst_swap_solution_geeks", deps = [
    "//code/utilities/printers:lib",
    "//code/utilities/data_structures/tree:binary_node",
    "//code/utilities/types/tree:tree_traversal",
    "//code/utilities/types/tree:tree_node_properties",
])