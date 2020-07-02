load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = [
        "//code/tools/ide/frame:frame_logic_updater",
        "//code/tools/ide/frame:fullscreener",
        "//code/tools/ide/settings:ide_settings",
        "//code/tools/ide/settings:ide_settings_getter",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/graphics/imgui:ui_renders",
        "//code/utilities/graphics/imgui/render:frame_renderer",
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "@imgui//:imgui_sdl_opengl3",
    ],
)
