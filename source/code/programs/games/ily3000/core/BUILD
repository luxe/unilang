package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp(
    name = "frame_renderer",
    deps = [
        "//code/programs/games/ily3000/assets:assets_loader",
        "//code/programs/games/ily3000/state:game_state",
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
    ],
)

hcp(
    name = "state_updater",
    deps = [
        "//code/programs/games/ily3000/assets:assets_loader",
        "//code/programs/games/ily3000/state:game_state",
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
    ],
)
