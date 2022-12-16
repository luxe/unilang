package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp_hdrs_derive(
    name = "frame_renderer",
    interface_deps = [
        "//code/programs/games/math_game/assets:assets_loader",
        "//code/programs/games/math_game/state:game_state",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "state_updater",
    interface_deps = [
        "//code/programs/games/math_game/assets:assets_loader",
        "//code/programs/games/math_game/core:character_select_screen_handler",
        "//code/programs/games/math_game/core:main_screen_handler",
        "//code/programs/games/math_game/state:game_state",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "main_screen_handler",
    interface_deps = [
        "//code/programs/games/math_game/assets:assets_loader",
        "//code/programs/games/math_game/state:game_state",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/time:timer_transition",
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "character_select_screen_handler",
    interface_deps = [
        "//code/programs/games/math_game/assets:assets_loader",
        "//code/programs/games/math_game/state:game_state",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/time:timer_transition",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/deps/external/sfml:lib",
    ],
)
