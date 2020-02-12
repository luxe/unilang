package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "frame_renderer", deps = [
    "@sfml//:sfml",
    "//code/utilities/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/keyboard/joycons:joycons",
    "//code/utilities/keyboard/joycons:joycon_state_getter",
    "//code/tools/games/crossword/assets:assets_loader",
    "//code/tools/games/crossword/state:game_state",
])

hcp(name = "state_updater", deps = [
    "@sfml//:sfml",
    "//code/utilities/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/keyboard/joycons:joycons",
    "//code/utilities/keyboard/joycons:joycon_state_getter",
    "//code/tools/games/crossword/assets:assets_loader",
    "//code/tools/games/crossword/state:game_state",
    "//code/utilities/keyboard/joycons:joystick_rotating_checker",
    "//code/utilities/math:math",
    "//code/utilities/keyboard/F310_gamepad/functions:f310_gamepads_state_getter",
])
