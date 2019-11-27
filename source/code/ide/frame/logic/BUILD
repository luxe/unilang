package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
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
        "//code/ide/settings:ide_settings",
        "//code/ide/frame/logic:frame_elements",
        "//code/ide/frame:mouse_selection_drawer",
        "//code/utilities/mouse/state:mouse_position_getter",
        "//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
        "//code/utilities/graphics/imgui/ui/window:window_position_finder",
        "//code/utilities/graphics/imgui/ui/draw/label/functions:label_drawer",
        "//code/ide/frame:label_cursor_action_doer",
        "//code/utilities/types/vectors/operators:lib",
        "//code/ide/frame:mouse_frame_getter",
        "//code/ide/frame:label_frame_getter",
        "//code/ide/frame:view_anchor_adjuster",
        "//code/utilities/mouse/state:mouse_state",
    ],
)