package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "reference_lookup_map",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "reference_lookup_map_getter",
    interface_deps = [
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/output/printers:lib",
        "//code/utilities/code/properties:schema_name_validator",
        "//code/utilities/types/map:lib",
    ],
)
