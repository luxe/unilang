package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "regular_game_phase", deps = [
    "@sfml//:sfml",
    "//code/tools/games/ur/assets:assets",
    "//code/tools/games/ur/state:game_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/math:math",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/strings/observers/converting:lib",
    "//code/utilities/types/map:lib",
    "//code/utilities/types/vectors/observers:size_frequency_counter",
    "//code/utilities/linguistics/speak:word_speaker",
    "//code/utilities/colors:converters",
    "//code/utilities/colors:color_transitioner",
    "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_event_synthesizer",
    "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
    "//code/utilities/games/ur:ur_logic",
    "//code/tools/games/ur/core/phases:roll_phase",
])

hcp(name = "roll_phase", deps = [
    "@sfml//:sfml",
    "//code/tools/games/ur/assets:assets",
    "//code/tools/games/ur/state:game_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/math:math",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/peripheral/keyboard/joycons:joystick_rotating_checker",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/strings/observers/converting:lib",
    "//code/utilities/types/map:lib",
    "//code/utilities/types/vectors/observers:size_frequency_counter",
    "//code/utilities/linguistics/speak:word_speaker",
    "//code/utilities/colors:converters",
    "//code/utilities/colors:color_transitioner",
    "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_event_synthesizer",
    "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
    "//code/utilities/games/ur:ur_logic",
    "//code/utilities/random/dice/ur:ur_dice",
])