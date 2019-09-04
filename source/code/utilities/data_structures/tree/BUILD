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