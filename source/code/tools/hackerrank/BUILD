package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/cpp:gtest.bzl", "gtest")

gtest(
    name = "bst_swap_test",
    deps = [
        "//code/tools/hackerrank:bst_swap_solution",
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