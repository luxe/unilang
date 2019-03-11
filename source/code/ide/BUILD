load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = ["@imgui//:imgui_sdl_opengl3",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/graphics/imgui:sdl_init_settings",
    "//code/utilities/graphics/imgui/ui:ui_renders",
    "//code/utilities/graphics/imgui/ui/window:window_renderer",
    "//code/utilities/graphics/imgui/ui/draw:mouse_events",
    "//code/utilities/graphics/imgui/ui/draw:mouse_events_checker",
    "//code/utilities/graphics/imgui/ui/draw:position",
    "//code/utilities/graphics/imgui/ui/draw:rectangle_drawer",
    "//code/utilities/graphics/imgui/ui/draw:pixel_settings",
    "//code/utilities/graphics/imgui/ui/draw:pixel_drawer",
    "//code/utilities/graphics/imgui/ui/draw:full_color_bitmap_drawer",
    "//code/transcompilers/unilang/tokens:get_tokens",
    "//code/transcompilers/unilang/language-and-theme-creator/font:unilang_font",
    "//code/utilities/types/char:lib"
    ],
)
