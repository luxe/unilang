package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "choices_map",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "choices_map_getter",
    interface_deps = [
        "//code/utilities/code/properties/choices:choices_map",
        "//code/utilities/code:class_access",
        "//code/utilities/code:storage_specifier",
        "//code/utilities/code:interface",
        "//code/utilities/code:reassignability",
        "//code/utilities/code/properties:schema_name_validator",
        "//code/utilities/types/map:lib",
    ],
)
