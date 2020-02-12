package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "frame_renderer", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
    "//code/tools/math_game/assets:assets_loader",
    "//code/tools/math_game/state:game_state",
])

hcp(name = "state_updater", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
    "//code/tools/math_game/assets:assets_loader",
    "//code/tools/math_game/state:game_state",
    "//code/tools/math_game/core:main_screen_handler",
    "//code/tools/math_game/core:character_select_screen_handler",
])

hcp(name = "main_screen_handler", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
    "//code/tools/math_game/assets:assets_loader",
    "//code/tools/math_game/state:game_state",
    "//code/utilities/time:timer_transition",
])

hcp(name = "character_select_screen_handler", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
    "//code/tools/math_game/assets:assets_loader",
    "//code/tools/math_game/state:game_state",
    "//code/utilities/time:timer_transition",
    "//code/utilities/types/vectors/observers:lib",
])