package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "save_state",
    interface_deps = [
        "//code/programs/ide/settings/data:ide_elements",
    ],
)

hcp_hdrs_derive(
    name = "save_state_loader",
    interface_deps = [
        "//code/programs/ide/global_actions:global_action_decider",
        "//code/programs/ide/settings/data:ide_elements",
        "//code/programs/ide/frame:validate_ide_element",
        "//code/programs/ide/frame:forward_compatible_element_upgrades",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/code/save/patches:patch_settings_getter",
        "//code/utilities/code/save:save_state",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/formats/json/attribute_check:json_attribute_checker",
        "//code/utilities/program/wrappers/zenity/file_selector",
        "//code/utilities/formats/compression/zlib:zlib_compressor",
        "//code/programs/ide/frame:apply_schema_to_elements",
        "//code/utilities/output/logging:debug_spdlog",
        "//code/utilities/patching:generic_patcher",
    ],
)

hcp_hdrs_derive(
    name = "save_state_saver",
    interface_deps = [
        "//code/programs/ide/global_actions:global_action_decider",
        "//code/programs/ide/settings/data:ide_elements",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/code/save/patches:patch_settings_getter",
        "//code/utilities/code/save:save_state",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/program/wrappers/zenity/file_selector",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/formats/compression/zlib:zlib_compressor",
    ],
)

hcp_hdrs_derive(
    name = "state_to_code_converter",
    interface_deps = [
        "//code/programs/ide/settings/data:ide_elements",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:buildable_schema_faced_tree_tokenizer",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/types/variant:lib",
    ],
)
