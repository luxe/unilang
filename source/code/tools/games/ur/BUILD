package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lX11",
        "-lGL",
        "-lXrandr",
        "-ludev",
    ],
    deps = [
        "//code/tools/games/ur/assets:assets_loader",
        "//code/tools/games/ur/core:frame_renderer",
        "//code/tools/games/ur/core:state_updater",
        "//code/tools/games/ur/state:game_state_getter",
        "//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/graphics/sfml:standard_sfml_game_loop",
        "@sdl2",
        "@glfw",
        "@opengl",
        "@sfml",
    ],
)

enum_cpp(
    name = "game_phase",
    values = [
        "main_menu",
        "starting_game",
        "playing_game",
        "end_game",
    ],
)
