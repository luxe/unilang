package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

enum_cpp(
    name = "global_action",
    values = [
        "fullscreen",
        "quit",
        "save",
        "load",
        "build",
        "none",
    ],
)

hcp(
    name = "global_action_decider",
    deps = [
        "//code/programs/ide/global_actions:global_action",
        "//code/utilities/peripheral/pc:pc_input_state",
    ],
)

hcp(
    name = "global_action_handler",
    deps = [
        "//code/programs/ide/global_actions:global_action",
        "//code/programs/ide/global_actions:global_action_decider",
        "//code/programs/ide/global_actions:main_menu_selector",
        "//code/programs/ide/global_actions:save_state_serializer",
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/code/save:state_to_code_converter",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:buildable_schema_faced_tree_tokenizer",
        "//code/utilities/deps/external/imgui:lib",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/graphics/sdl:sdl_fullscreener",
        "//code/utilities/program/wrappers/zenity/file_selector",
    ],
)

hcp(
    name = "save_state_serializer",
    deps = [
        "//code/programs/ide/frame:apply_schema_to_elements",
        "//code/programs/ide/global_actions:global_action",
        "//code/programs/ide/global_actions:global_action_decider",
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/code/save:save_state_loader",
        "//code/utilities/code/save:save_state_saver",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:buildable_schema_faced_tree_tokenizer",
        "//code/utilities/deps/external/imgui:lib",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/graphics/sdl:sdl_fullscreener",
        "//code/utilities/program/wrappers/zenity/file_selector",
    ],
)

hcp(
    name = "main_menu_selector",
    deps = [
        "//code/programs/ide/frame:apply_schema_to_elements",
        "//code/programs/ide/global_actions:global_action",
        "//code/programs/ide/global_actions:global_action_decider",
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/code/save:save_state_loader",
        "//code/utilities/code/save:save_state_saver",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:buildable_schema_faced_tree_tokenizer",
        "//code/utilities/data_structures/graphics/objects/faced_tree:tree_label_active_finder",
        "//code/utilities/deps/external/imgui:lib",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/graphics/sdl:sdl_fullscreener",
        "//code/utilities/program/wrappers/zenity/file_selector",
        "//code/utilities/types/variant:lib",
    ],
)
