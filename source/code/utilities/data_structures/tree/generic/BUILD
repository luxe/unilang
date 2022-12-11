package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")

hcp_hdrs_derive(
    name = "int_tree",
    interface_deps = [
        "//code/utilities/deps/external/tree_hh:lib",
    ],
)

hcp_hdrs_derive(
    name = "string_tree",
    interface_deps = [
        "//code/utilities/deps/external/tree_hh:lib",
    ],
)

hcp_hdrs_derive(
    name = "string_int_tree",
    interface_deps = [
        "//code/utilities/deps/external/tree_hh:lib",
    ],
)

hcp_hdrs_derive(
    name = "child_lookup_map",
    interface_deps = [
        "//code/utilities/deps/external/tree_hh:lib",
    ],
)

hcp_hdrs_derive(
    name = "child_lookup_map_find",
    interface_deps = [
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
    ],
)

hcp_hdrs_derive(
    name = "string_to_string_tree",
    interface_deps = [
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/types/strings/observers/counters:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/tree/converters:depth_list",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/deps/external/tree_hh:lib",
    ],
)

hcp_hdrs_derive(
    name = "string_tree_to_child_lookup_map",
    interface_deps = [
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/types/strings/observers/counters:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/tree:full_path_name",
        "//code/utilities/types/tree/converters:depth_list",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/deps/external/tree_hh:lib",
    ],
)
