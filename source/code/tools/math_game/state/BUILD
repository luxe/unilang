package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "current_screen",
    values = [
    "main",
    "character_select",
    "game_select",
    "game",
    "after_game",
    ]
)

hcp(name = "game_state", deps = [
    "//code/utilities/keyboard/joycons:joycons",
    "//code/tools/math_game/state:current_screen",
    "@sfml//:sfml",
])

hcp(name = "game_state_getter", deps = [
    "//code/utilities/keyboard/joycons:joycons",
    "//code/tools/math_game/state:current_screen",
    "//code/tools/math_game/state:game_state",
])