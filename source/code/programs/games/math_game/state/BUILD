package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "current_screen",
    values = [
        "main",
        "character_select",
        "game_select",
        "game",
        "after_game",
    ],
)

hcp(
    name = "game_state",
    deps = [
        "//code/programs/games/math_game/state:current_screen",
        "//code/programs/games/math_game/state:transition_clock",
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/peripheral/keyboard/joycons",
    ],
)

hcp(
    name = "transition_clock",
    deps = [
        "//code/programs/games/math_game/state:current_screen",
        "//code/utilities/deps/external/sfml:lib",
        "//code/utilities/peripheral/keyboard/joycons",
    ],
)

hcp(
    name = "game_state_getter",
    deps = [
        "//code/programs/games/math_game/state:current_screen",
        "//code/programs/games/math_game/state:game_state",
        "//code/utilities/peripheral/keyboard/joycons",
    ],
)
