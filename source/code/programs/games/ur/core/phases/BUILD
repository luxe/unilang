package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp(
    name = "regular_game_phase",
    deps = [
        "//code/programs/games/ur/assets",
        "//code/programs/games/ur/core/phases:choose_phase",
        "//code/programs/games/ur/core/phases:player_change",
        "//code/programs/games/ur/core/phases:roll_phase",
        "//code/programs/games/ur/state:game_state",
        "//code/utilities/colors/converters",
        "//code/utilities/colors/transformers:color_transitioner",
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/games/ur:ur_logic",
        "//code/utilities/linguistics/speak:word_speaker",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_event_synthesizer",
        "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/observers:size_frequency_counter",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "roll_phase",
    deps = [
        "//code/programs/games/ur/assets",
        "//code/programs/games/ur/state:game_state",
        "//code/utilities/colors/converters",
        "//code/utilities/colors/transformers:color_transitioner",
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/games/ur:ur_logic",
        "//code/utilities/linguistics/speak:word_speaker",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_event_synthesizer",
        "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
        "//code/utilities/random/dice/ur:ur_dice",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/observers:size_frequency_counter",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "choose_phase",
    deps = [
        "//code/programs/games/ur/assets",
        "//code/programs/games/ur/core/phases:player_change",
        "//code/programs/games/ur/state:game_state",
        "//code/utilities/colors/converters",
        "//code/utilities/colors/transformers:color_transitioner",
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/games/ur:ur_logic",
        "//code/utilities/linguistics/speak:word_speaker",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_event_synthesizer",
        "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/observers:size_frequency_counter",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "player_change",
    deps = [
        "//code/programs/games/ur/assets",
        "//code/programs/games/ur/state:game_state",
        "//code/utilities/colors/converters",
        "//code/utilities/colors/transformers:color_transitioner",
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/games/ur:ur_logic",
        "//code/utilities/linguistics/speak:word_speaker",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_event_synthesizer",
        "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
        "//code/utilities/random/dice/ur:ur_dice",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/observers:size_frequency_counter",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)
