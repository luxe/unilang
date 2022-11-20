package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "node_edge_data",
    interface_deps = [
        "//code/utilities/data_structures/counters/unique_counter",
    ],
)

hcp_hdrs_derive(
    name = "timed_connection",
    interface_deps = [
        "//code/utilities/data_structures/graph/basic:connection",
        "//code/utilities/data_structures/graph/basic:event_interval",
    ],
)

hcp_hdrs_derive(
    name = "event_interval",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "connection",
    interface_deps = [
        "//code/utilities/data_structures/graph/basic:edge_type",
    ],
)

enum_cpp(
    name = "edge_type",
    values = [
        "directed",
        "undirected",
    ],
)
