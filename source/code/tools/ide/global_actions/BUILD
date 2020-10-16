package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/hcp:hcp.bzl", "hcp")

enum_cpp(
    name = "global_action",
    values = [
        "fullscreen",
        "quit",
        "save",
        "none",
    ],
)

hcp(
    name = "global_action_decider",
    deps = [
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/tools/ide/global_actions:global_action",
    ],
)

hcp(
    name = "global_action_handler",
    deps = [
        "//code/tools/ide/settings:ide_settings",
        "//code/tools/ide/global_actions:global_action_decider",
        "@imgui//:imgui_sdl_opengl3",
        "//code/utilities/graphics/sdl:sdl_fullscreener",
        "//code/utilities/program/wrappers/zenity/file_selector:file_selector",
        "//code/utilities/formats/json/functions:lib",
    ],
)
