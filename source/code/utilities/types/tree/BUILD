package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:gtest.bzl", "gtest")


hcp(name = "tree_traversal",deps=[
"//code/utilities/data_structures/tree:binary_node",
"//code/utilities/types/tree:tree_node_properties",
"//code/utilities/data_structures/tree:binary_node_with_height",
])

hcp(name = "tree_node_properties",deps=[
"//code/utilities/data_structures/tree:binary_node",
])


gtest(
    name = "tree_traversal_test",
    deps = [
        "//code/utilities/types/tree:tree_traversal",
        "//code/utilities/data_structures/tree:binary_node",
        "//code/utilities/types/tree/bst:annotated_bst_fix",
        "//code/utilities/types/tree/bst:annotated_bst_state",
        "//code/utilities/data_structures/tree:binary_nodes",
        "//code/utilities/types/tree/bst:prebuilt_bst_trees",
    ]
)