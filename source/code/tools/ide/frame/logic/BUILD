package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "frame_logic_updater",
    deps = [
        "//code/tools/ide/settings:ide_settings",
        "//code/utilities/graphics/imgui/render:frame_elements",
        "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_selection_drawer",
        "//code/utilities/peripheral/mouse/state:mouse_position_getter",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/graphics/imgui/ui/window:window_position_finder",
        "//code/utilities/data_structures/graphics/objects/functions:label_drawer",
        "//code/tools/ide/frame:label_cursor_action_doer",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_frame_getter",
        "//code/tools/ide/frame:label_frame_getter",
        "//code/utilities/data_structures/graphics/objects/mouse/draw:view_anchor_adjuster",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/keyboard:key_detector",
        "//code/utilities/peripheral/keyboard/state:imgui_keyboard_state_getter",
        "//code/utilities/peripheral/pc:pc_input_state_getter",
        "//code/utilities/peripheral/pc:pc_input_state",
    ],
)
