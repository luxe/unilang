package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "buildable_schema_faced_tree_state",
    interface_deps = [
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/code/properties/style_theme:style_lookup_map",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:schema_path_settings",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
    ],
)

hcp_hdrs_derive(
    name = "schema_path_settings",
    interface_deps = [
        "//code/utilities/code/properties/references:reference_lookup_map",
        "//code/utilities/code/properties/style_theme:style_lookup_map",
        "//code/utilities/code/properties/choices:choices_map",
        "//code/utilities/code/properties/peek:peek_map",
        "//code/utilities/data_structures/graphics/objects/buildable_faced_tree/data:buildable_face_tree",
        "//code/utilities/data_structures/tree/generic:child_lookup_map",
        "//code/utilities/code/properties/special_draw:special_draw_map",
    ],
)

hcp_and_hcp_pos_hdrs_derive(
    name = "buildable_schema_faced_tree",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:buildable_schema_faced_tree_state",
    ],
)

hcp_hdrs_derive(
    name = "default_schema_path_settings",
    interface_deps = [
        "//code/utilities/code/properties/reference_depth:default_reference_depth_map_getter",
        "//code/utilities/code/properties/references:reference_lookup_map_getter",
        "//code/utilities/code/properties/style_theme:style_lookup_map_getter",
        "//code/utilities/code/properties/choices:choices_map_getter",
        "//code/utilities/code/properties/peek:peek_map_getter",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:buildable_schema_faced_tree_default_schema",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree/data:schema_path_settings",
        "//code/utilities/code/save/patches:schema_patch_settings_getter",
        "//code/utilities/code/properties/special_draw:special_draw_map_getter",
    ],
)
