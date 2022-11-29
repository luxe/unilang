package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp_hdrs_derive(
    name = "frame_renderer",
    interface_deps = [
        "//code/programs/games/filler/gui/state:game_state",
        "//code/programs/games/filler/gui/assets:assets",
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
        "//code/programs/games/filler/gui/state:game_state",
        "//code/programs/games/filler/gui/assets:assets",
        "//code/utilities/colors/converters",
        "//code/utilities/colors/transformers:color_transitioner",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/linguistics/build_word/game:puzzle_builder",
        "//code/utilities/linguistics/speak:word_speaker",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_event_synthesizer",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_gamepads_state_getter",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/sfml:sfml_text",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/observers:size_frequency_counter",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/programs/games/filler/gui/state:game_state_getter",
        "//code/utilities/deps/external/sfml:lib",
        "//code/programs/games/filler/gui/assets:assets_loader",
    ],
)
