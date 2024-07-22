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
        "delete",
        "undo",
        "none",
    ],
)

hcp_hdrs_derive(
    name = "global_action_decider",
    interface_deps = [
        "//code/programs/ide/global_actions:global_action",
        "//code/utilities/peripheral/pc:pc_input_state",
    ],
)

hcp_hdrs_derive(
    name = "global_action_handler",
    interface_deps = [
        "//code/programs/ide/global_actions:global_action",
        "//code/programs/ide/global_actions:global_action_decider",
        "//code/programs/ide/global_actions:global_element_deleter",
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
        "//code/programs/ide/global_actions:global_element_builder",
    ],
)

hcp_hdrs_derive(
    name = "global_element_builder",
    interface_deps = [
        "//code/programs/ide/global_actions:global_action",
        "//code/programs/ide/global_actions:global_action_decider",
        "//code/programs/ide/global_actions:main_menu_selector",
        "//code/programs/ide/global_actions:save_state_serializer",
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/code:concept_string_tree_parser",
        "//code/utilities/data_structures/graphics/objects/faced_label/premade:faced_label_premades",
        "//code/utilities/code/save:state_to_code_converter",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buildable_schema_faced_tree:buildable_schema_faced_tree_tokenizer",
        "//code/utilities/deps/external/imgui:lib",
        "//code/utilities/formats/json/converters:json_file_io",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/graphics/sdl:sdl_fullscreener",
        "//code/utilities/program/wrappers/zenity/file_selector",
        "//code/utilities/data_structures/graphics/objects/label/style:default_label_styles",
    ],
)

hcp_hdrs_derive(
    name = "save_state_serializer",
    interface_deps = [
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

hcp_hdrs_derive(
    name = "main_menu_selector",
   interface_deps = [
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

hcp_hdrs_derive(
    name = "global_element_deleter",
   interface_deps = [
        "//code/utilities/graphics/sdl:sdl_fullscreener",
        "//code/programs/ide/settings/data:ide_settings",
        "//code/programs/ide/frame:find_mouse_over_index",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)