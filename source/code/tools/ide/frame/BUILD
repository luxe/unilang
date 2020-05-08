package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "text_box_action",
    values = [
    "navigate_forward",
    "navigate_backward",
    "select_forward",
    "select_backward",
    "add_chars",
    "backspace",
    "select_all",
    "copy",
    "paste",
    "delete",
    "none",
    ]
)

hcp(
    name = "label_frame_getter",
    deps = [
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/tools/ide/settings:ide_settings",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_selection_drawer",
        "//code/utilities/peripheral/mouse/state:mouse_position_getter",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/graphics/imgui/window:window_position_finder",
        "//code/utilities/data_structures/graphics/objects/functions:label_drawer",
        "//code/tools/ide/frame:label_cursor_action_doer",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_frame_getter",
        "//code/utilities/data_structures/graphics/objects/functions:grid_label_drawer",
        "//code/utilities/data_structures/graphics/objects/functions:tree_label_drawer",
        "//code/utilities/data_structures/graphics/objects/functions:button_tree_label_drawer",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/data_structures/graphics/objects/functions:cursor_drawer",
        "//code/utilities/graphics/imgui:mechanics",
        "//code/utilities/data_structures/graphics/objects/grid/faced/slider:slider_drawer",
    ],
)


hcp(name = "fullscreener", deps = [
    "@imgui//:imgui_sdl_opengl3",
    "//code/tools/ide/settings:ide_settings",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/peripheral/keyboard:key_detector",
])

hcp(name = "label_cursor_action_doer", deps = [
    "@imgui//:imgui_sdl_opengl3",
    "//code/tools/ide/settings:ide_settings",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/graphics/imgui:ui_renders",
    "//code/utilities/graphics/imgui/window:window_renderer",
    "//code/utilities/graphics/imgui/window:window_position_finder",
    "//code/utilities/peripheral/keyboard:key_detector",
    "//code/tools/ide/frame:text_box_action_decider",
    "//code/utilities/data_structures/graphics/objects/cursor:label_cursor_mover",
    "//code/utilities/data_structures/graphics/objects/grid/faced/regular:positioned_label",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/peripheral/pc:pc_input_state",
])

hcp(name = "text_box_action_decider", deps = [
    "@imgui//:imgui_sdl_opengl3",
    "//code/tools/ide/settings:ide_settings",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/tools/ide/frame:text_box_action",
    "//code/utilities/peripheral/keyboard:key_detector",
    "//code/utilities/peripheral/pc:pc_input_state",
    "//code/utilities/data_structures/graphics/objects/mouse:anchor_mouse",
])
