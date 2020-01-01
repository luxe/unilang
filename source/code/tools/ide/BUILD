load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = ["@imgui//:imgui_sdl_opengl3",
        "//code/utilities/graphics/imgui:mechanics",
        "//code/utilities/graphics/imgui/sdl:sdl_init_settings",
        "//code/utilities/graphics/imgui/ui:ui_renders",
        "//code/ide/settings:ide_settings",
        "//code/ide/settings:ide_settings_getter",
        "//code/ide/frame:frame_renderer",
        "//code/ide/frame/logic:frame_logic_updater",
        "//code/ide/frame/logic:frame_elements",
    ],
)
