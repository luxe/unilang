package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "game_state",
    interface_deps = [
        "//code/programs/games/ur:game_phase",
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/games/ur/state:ur_game_state",
        "//code/utilities/linguistics/build_word/game:build_word_puzzle",
        "//code/utilities/linguistics/build_word/game/settings:build_word_game_settings",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepads",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepads_phases",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "game_state_getter",
    interface_deps = [
        "//code/programs/games/ur/state:game_state",
        "//code/utilities/games/ur:ur_state_getter",
        "//code/utilities/linguistics/build_word/game:puzzle_builder",
        "//code/utilities/linguistics/build_word/game/settings:build_word_game_settings_getter",
        "//code/utilities/peripheral/keyboard/joycons",
    ],
)
