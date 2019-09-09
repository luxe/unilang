package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "annotated_bst_fix", deps = [
    "//code/utilities/types/tree/bst:annotated_bst_state",
    "//code/utilities/types/tree:tree_traversal",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/shell:lib",
    "//code/utilities/types/char:lib",
])

hcp(name = "annotated_bst_state", deps = [
    "//code/utilities/data_structures/tree:binary_node"
])