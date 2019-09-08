package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/cpp:gtest.bzl", "gtest")
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

gtest(
    name = "bst_swap_test",
    deps = [
        "//code/tools/hackerrank:bst_swap_solution_sliding_window_two_ptrs",
        "//code/tools/hackerrank:bst_swap_solution_in_out",
        "//code/tools/hackerrank:bst_swap_solution_geeks",
        "//code/tools/hackerrank:bst_swap_solution_geeks_four_ptrs",
        "//code/tools/hackerrank:bst_swap_solution_geeks_three_ptrs",
        "//code/utilities/types/tree:tree_traversal",
    ]
)

# The algorithms
enum_cpp(
    name = "bst_swap_algorithm",
    values = [
    "hackerrank_recursive_five",
    "hackerrank_recursive_four",
    "sliding_window_and_pair",
    "inorder_outorder_three",
    ]
)
hcp(name = "bst_swap_solution_geeks", deps = [
    "//code/utilities/printers:lib",
    "//code/utilities/data_structures/tree:binary_node",
    "//code/utilities/types/tree:tree_traversal",
    "//code/utilities/types/tree:tree_node_properties",
])
hcp(name = "bst_swap_solution_geeks_four_ptrs", deps = [
    "//code/utilities/printers:lib",
    "//code/utilities/data_structures/tree:binary_node",
    "//code/utilities/types/tree:tree_traversal",
    "//code/utilities/types/tree:tree_node_properties",
])
hcp(name = "bst_swap_solution_geeks_three_ptrs", deps = [
    "//code/utilities/printers:lib",
    "//code/utilities/data_structures/tree:binary_node",
    "//code/utilities/types/tree:tree_traversal",
    "//code/utilities/types/tree:tree_node_properties",
])

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