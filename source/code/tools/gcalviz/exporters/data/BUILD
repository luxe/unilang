package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name="node_edge_data", deps = [
    "//code/utilities/data_structures/unique_counter:unique_counter",
])

hcp(name="edge_data", deps = [
    ":event_interval",
    ":connection",
])

hcp(name="event_interval", deps = [
])
hcp(name="connection", deps = [
    ":edge_type",
])

enum_cpp(name = "edge_type",
values = [
"directed"
,"undirected"
])