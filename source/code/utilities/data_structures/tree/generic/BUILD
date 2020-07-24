package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp(
    name = "int_tree",
    deps = [
        "@tree",
    ],
)

hcp(
    name = "string_tree",
    deps = [
        "@tree",
    ],
)

hcp(
    name = "string_to_string_tree",
    deps = [
        "//code/utilities/types/strings/observers/counters:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/tree/converters:depth_list",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/types/strings/transformers/removing:lib",
        "@tree",
    ],
)
