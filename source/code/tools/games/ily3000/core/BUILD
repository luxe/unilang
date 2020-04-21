package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")

hcp(name = "frame_renderer", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
    "//code/tools/games/ily3000/assets:assets_loader",
    "//code/tools/games/ily3000/state:game_state",
])

hcp(name = "state_updater", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
    "//code/tools/games/ily3000/assets:assets_loader",
    "//code/tools/games/ily3000/state:game_state",
    "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
    "//code/utilities/math:math",
])
