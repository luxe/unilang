package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "frame_elements",
    deps = [
        "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
        "//code/utilities/graphics/imgui/ui/draw/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:positioned_full_color_bitmap",
    ],
)

hcp(
    name = "frame_logic_updater",
    deps = [
        "//code/tools/ide/settings:ide_settings",
        "//code/tools/ide/frame/logic:frame_elements",
        "//code/tools/ide/frame:mouse_selection_drawer",
        "//code/utilities/peripheral/mouse/state:mouse_position_getter",
        "//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
        "//code/utilities/graphics/imgui/ui/window:window_position_finder",
        "//code/utilities/graphics/imgui/ui/draw/label/functions:label_drawer",
        "//code/tools/ide/frame:label_cursor_action_doer",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/tools/ide/frame:mouse_frame_getter",
        "//code/tools/ide/frame:label_frame_getter",
        "//code/tools/ide/frame:view_anchor_adjuster",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/keyboard:key_detector",
        "//code/utilities/peripheral/keyboard/state:imgui_keyboard_state_getter",
    ],
)