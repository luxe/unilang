#http://llimllib.github.io/pymag-trees/
package(
    default_visibility = ["//visibility:public"],
)
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "binary_node_child_type",
    values = [
        "left",
        "right"
    ]
)

cc_library(
    name = "binary_node",
    hdrs = ["binary_node.hpp"],
    deps = [
    ]
)

cc_library(
    name = "binary_nodes",
    hdrs = ["binary_nodes.hpp"],
    deps = [
        "//code/utilities/data_structures/tree:binary_node"
    ]
)

cc_library(
    name = "binary_node_with_height",
    hdrs = ["binary_node_with_height.hpp"],
    deps = [
        "//code/utilities/data_structures/tree:binary_node"
    ]
)

cc_library(
    name = "bst_tree_example",
    hdrs = ["bst_tree_example.hpp"],
    deps = [
        "//code/utilities/data_structures/tree:binary_node"
    ]
)