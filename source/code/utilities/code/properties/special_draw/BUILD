package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "special_draw",
    values = [
        "none",
        "graph",
    ],
)

hcp_hdrs_derive(
    name = "special_draw_map",
    interface_deps = [
        "//code/utilities/code/properties/special_draw:special_draw",
    ],
)

hcp_hdrs_derive(
    name = "special_draw_map_getter",
    interface_deps = [
        "//code/utilities/code/properties/special_draw:special_draw_map",
        "//code/utilities/code:class_access",
        "//code/utilities/code/properties:schema_name_validator",
        "//code/utilities/types/map:lib",
        "//code/utilities/code/properties/special_draw:special_draw",
    ],
)
