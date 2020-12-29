load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "unilang_ide",
    deps = [
    "//code/tools/ide/settings:ide_settings",
    "//code/tools/ide/settings:ide_settings_getter",
    "//code/utilities/data_structures/graphics/objects:frame_elements",
    "//code/utilities/graphics/imgui/loop:mechanics",
    "//code/utilities/graphics/imgui:ui_renders",
    "//code/utilities/graphics/imgui/render:frame_renderer",
    "//code/tools/ide/frame:frame_logic_updater",
    "//code/tools/ide/global_actions:global_action_handler",
    "//code/tools/ide/program_options:lib",
    "//code/tools/ide/global_actions:save_state_serializer",
    "@imgui//:imgui_sdl_opengl3",
],
)

cpp_main(
    name = "main",
    deps = [
        "//code/tools/ide:unilang_ide",
        "//code/tools/ide/program_options:lib",
    ],
)