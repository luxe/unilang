package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "frame_renderer", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
    "//code/tools/games/word_build/gui/assets:assets_loader",
    "//code/tools/games/word_build/gui/state:game_state",
])

hcp(name = "state_updater", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
    "//code/tools/games/word_build/gui/assets:assets_loader",
    "//code/tools/games/word_build/gui/state:game_state",
    "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
    "//code/utilities/math:math",
    "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_gamepads_state_getter",
    "//code/utilities/linguistics/build_word/game:puzzle_builder",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/strings/observers/converting:lib",
    "//code/utilities/types/vectors/transformers:lib",
])
