package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "save_state",
    deps = [
        "//code/tools/ide/settings:ide_elements",
    ],
)

hcp(
    name = "save_state_loader",
    deps = [
        "//code/tools/ide/settings:ide_elements",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/tools/ide/global_actions:global_action_decider",
        "//code/utilities/program/wrappers/zenity/file_selector:file_selector",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/code/state:save_state",
    ],
)

hcp(
    name = "save_state_saver",
    deps = [
        "//code/tools/ide/settings:ide_elements",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/tools/ide/global_actions:global_action_decider",
        "//code/utilities/program/wrappers/zenity/file_selector:file_selector",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/code/state:save_state",
    ],
)

hcp(
    name = "state_to_code_converter",
    deps = [
        "//code/tools/ide/settings:ide_elements",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/types/variant:lib",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:buildable_schema_faced_tree_tokenizer",
    ],
)