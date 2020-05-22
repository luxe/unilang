package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")

hcp(
    name = "frame_renderer",
    deps = [
        "//code/tools/games/word_build/gui/assets:assets_loader",
        "//code/tools/games/word_build/gui/state:game_state",
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
        "//code/tools/games/word_build/gui/assets:assets_loader",
        "//code/tools/games/word_build/gui/core:game_over_phase",
        "//code/tools/games/word_build/gui/core:regular_game_phase",
        "//code/tools/games/word_build/gui/core:start_game_phase",
        "//code/tools/games/word_build/gui/core:title_game_phase",
        "//code/tools/games/word_build/gui/state:game_state",
        "//code/utilities/colors:color_transitioner",
        "//code/utilities/colors:converters",
        "//code/utilities/formats/json/functions:lib",
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
        "@sfml",
    ],
)

hcp(
    name = "start_game_phase",
    deps = [
        "//code/tools/games/word_build/gui/assets",
        "//code/tools/games/word_build/gui/state:game_state",
        "//code/utilities/linguistics/build_word/game:puzzle_builder",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
        "//code/utilities/types/vectors/observers:lib",
        "@sfml",
    ],
)

hcp(
    name = "game_over_phase",
    deps = [
        "//code/tools/games/word_build/gui/assets",
        "//code/tools/games/word_build/gui/state:game_state",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
        "//code/utilities/types/strings/sfml:sfml_text",
        "//code/utilities/types/vectors/observers:lib",
        "@sfml",
    ],
)

hcp(
    name = "title_game_phase",
    deps = [
        "//code/tools/games/word_build/gui/assets",
        "//code/tools/games/word_build/gui/state:game_state",
        "//code/utilities/colors:converters",
        "//code/utilities/colors:screen_position_to_rgb",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
        "//code/utilities/random:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/strings/sfml:sfml_text",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "@sfml",
    ],
)

hcp(
    name = "regular_game_phase",
    deps = [
        "//code/tools/games/word_build/gui/assets",
        "//code/tools/games/word_build/gui/assets:assets_loader",
        "//code/tools/games/word_build/gui/state:game_state",
        "//code/utilities/colors:color_transitioner",
        "//code/utilities/colors:converters",
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/linguistics/build_word/game:puzzle_builder",
        "//code/utilities/linguistics/speak:word_speaker",
        "//code/utilities/math",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_gamepads_state_getter",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/observers:size_frequency_counter",
        "//code/utilities/types/vectors/transformers:lib",
        "@sfml",
    ],
)
