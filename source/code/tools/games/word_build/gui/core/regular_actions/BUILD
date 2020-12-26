package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "regular_actions",
    deps = [
    ],
)

hcp(
    name = "regular_actions_getter",
    deps = [
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_gamepads_state_getter",
        "//code/tools/games/word_build/gui/core/regular_actions:regular_actions",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepad_phases",
    ],
)