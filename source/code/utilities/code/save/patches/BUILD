package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "patch_settings_getter",
    interface_deps = [
        "//code/programs/ide/global_actions:global_action_decider",
        "//code/programs/ide/settings/data:ide_elements",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/code/save:save_state",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/program/wrappers/zenity/file_selector",
    ],
)

hcp_hdrs_derive(
    name = "schema_patch_settings_getter",
    interface_deps = [
        "//code/programs/ide/global_actions:global_action_decider",
        "//code/programs/ide/settings/data:ide_elements",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/code/save:save_state",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/program/wrappers/zenity/file_selector",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_tree:button_face_tree_full_path_name",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_first_name",
    ],
)
