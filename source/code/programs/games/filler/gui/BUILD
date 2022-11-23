package(default_visibility = ["//visibility:public"])

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
    ],
    deps = [
        "//code/programs/games/filler/gui/assets:assets_loader",
        "//code/programs/games/filler/gui/state:game_state_getter",
        "//code/programs/games/filler/gui/core:frame_renderer",
        "//code/programs/games/filler/gui/core:state_updater",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/graphics/sfml:standard_sfml_game_loop",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/deps/external/gl:lib",
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
