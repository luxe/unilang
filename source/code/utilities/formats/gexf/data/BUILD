package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "gexf_attribute",
    interface_deps = [
        "//code/utilities/formats/json/extraction:json_extraction_settings",
    ],
)

hcp_hdrs_derive(
    name = "gexf_metadata",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "gexf_data",
    interface_deps = [
        "//code/utilities/formats/gexf/data:gexf_attribute",
        "//code/utilities/formats/gexf/data:gexf_metadata",
        "//code/utilities/data_structures/graph/basic:node_edge_data",
    ],
)
