package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "object_to_counted_objects",
    deps = [
        "//code/utilities/linguistics/counted_object",
    ],
)

hcp(
    name = "graph_builder",
    deps = [
        "//code/utilities/data_structures/graph:object_to_counted_objects",
        "//code/utilities/data_structures/graph/unique_str_vertex_graph:lib",
        "@cpp_graph_library//:lib",
    ],
)
