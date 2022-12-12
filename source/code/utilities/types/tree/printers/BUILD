package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:gtest.bzl", "gtest")

hcp_hdrs_derive(
    name = "print_tree_as_json_blob_tree",
    interface_deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/tree/bst:annotated_bst_state",
        "//code/utilities/types/tree/bst:annotated_bst_visualizer",
        "//code/utilities/types/tree/bst:tree_node_properties",
        "//code/utilities/types/tree/bst:tree_traversal",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/types/strings/creators:lib",
    ],
)