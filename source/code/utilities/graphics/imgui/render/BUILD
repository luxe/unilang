package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "frame_renderer",
    deps = ["@imgui//:imgui_sdl_opengl3",
        "//code/tools/ide/settings:ide_settings",
        "//code/utilities/graphics/imgui:ui_renders",
        "//code/utilities/graphics/imgui/window:window_renderer",
        "//code/utilities/graphics/imgui/window:window_position_finder",
        "//code/utilities/data_structures/graphics/objects/functions:label_drawer",
        "//code/utilities/graphics/imgui:imgui_type_utility",
        "//code/tools/ide/frame:fullscreener",
        "//code/utilities/graphics/imgui:mechanics",
        "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_selection_drawer",
        "//code/utilities/peripheral/keyboard:key_detector",
        "//code/tools/ide/frame:label_cursor_action_doer",
        "//code/utilities/graphics/imgui/render/elements:line_drawer",
        "//code/utilities/peripheral/mouse/state:mouse_position_getter",
        "//code/utilities/graphics/imgui/render/elements:multi_color_bitmap_drawer",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/types/variant:lib",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:positioned_full_color_bitmap",
        "//code/utilities/peripheral/pc:pc_input_state_getter",
    ],
)
