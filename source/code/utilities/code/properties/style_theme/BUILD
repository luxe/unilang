package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "style_lookup_map",
    interface_deps = [
        "//code/utilities/code/properties/style_theme",
        "//code/utilities/data_structures/graphics/objects/label/style:label_styles",
    ],
)

hcp_hdrs_derive(
    name = "style_lookup_map_getter",
    interface_deps = [
        "//code/utilities/code/properties/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/label/style:default_label_styles",
        "//code/utilities/code/properties:schema_name_validator",
        "//code/utilities/types/map:lib",
    ],
)

hcp_hdrs_derive(
    name = "style_theme",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/label/style:label_styles",
    ],
)
