package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "everything_drawer",
    deps = ["@imgui//:imgui_sdl_opengl3",
        "//code/ide/settings:ide_settings",
        "//code/utilities/graphics/imgui/ui:ui_renders",
        "//code/utilities/graphics/imgui/ui/window:window_renderer",
        "//code/utilities/graphics/imgui/ui/window:window_position_finder",
        "//code/utilities/graphics/imgui/ui/draw/label:label_drawer",
        "//code/utilities/graphics/imgui/ui/draw:imgui_type_utility",
        "//code/ide/frame:fullscreener",
        "//code/utilities/graphics/imgui:mechanics",
        "//code/ide/frame:mouse_selection_drawer",
        "//code/utilities/keyboard:key_detector",
        "//code/ide/frame:label_cursor_action_doer",
        "//code/utilities/graphics/imgui/ui/draw/line:line_drawer",
        "//code/utilities/graphics/imgui/ui/draw:mouse_position_getter",
        "//code/utilities/graphics/imgui/ui/draw/bitmap/multi_color_bitmap:multi_color_bitmap_drawer",
    ],
)