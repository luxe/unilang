package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")

hcp(
    name = "frame_renderer",
    deps = [
        "//code/tools/games/ily3000/assets:assets_loader",
        "//code/tools/games/ily3000/state:game_state",
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "@sfml",
    ],
)

hcp(
    name = "state_updater",
    deps = [
        "//code/tools/games/ily3000/assets:assets_loader",
        "//code/tools/games/ily3000/state:game_state",
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
        "@sfml",
    ],
)
