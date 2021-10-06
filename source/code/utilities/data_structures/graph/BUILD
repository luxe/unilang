package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "object_to_counted_objects",
    interface_deps = [
        "//code/utilities/linguistics/counted_object",
    ],
)

hcp_hdrs_derive(
    name = "graph_builder",
    interface_deps = [
        "//code/utilities/data_structures/graph:object_to_counted_objects",
        "//code/utilities/data_structures/graph/unique_str_vertex_graph:lib",
        "//code/utilities/deps/external/cpp_graph:lib",
    ],
)
