package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "frame_renderer",
    deps = ["@imgui//:imgui_sdl_opengl3",
        "//code/ide/settings:ide_settings",
        "//code/utilities/graphics/imgui/ui:ui_renders",
        "//code/utilities/graphics/imgui/ui/window:window_renderer",
        "//code/utilities/graphics/imgui/ui/window:window_position_finder",
        "//code/utilities/graphics/imgui/ui/draw/label:label_drawer",
        "//code/utilities/graphics/imgui/ui/draw:imgui_type_utility",
        "//code/ide/frame:cursor_mover",
        "//code/ide/frame:fullscreener",
        "//code/ide/frame:background_drawer",
        "//code/utilities/graphics/imgui:mechanics",
        "//code/ide/frame:mouse_selection_drawer",
    ],
)

hcp(
    name = "cursor_mover",
    deps = ["@imgui//:imgui_sdl_opengl3",
        "//code/ide/settings:ide_settings",
        "//code/utilities/graphics/imgui/ui:ui_renders",
    ],
)


hcp(name = "fullscreener", deps = [
    "@imgui//:imgui_sdl_opengl3",
    "//code/ide/settings:ide_settings",
    "//code/utilities/graphics/imgui:mechanics",
])


hcp(name = "background_drawer", deps = [
    "@imgui//:imgui_sdl_opengl3",
    "//code/ide/settings:ide_settings",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/graphics/imgui/ui/draw/rectangle:rectangle_drawer",
])

hcp(name = "mouse_selection_drawer", deps = [
    "@imgui//:imgui_sdl_opengl3",
    "//code/ide/settings:ide_settings",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/graphics/imgui/ui/draw/rectangle:rectangle_drawer",
])