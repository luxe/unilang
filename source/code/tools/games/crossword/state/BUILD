package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "game_state", deps = [
    "//code/utilities/keyboard/joycons:joycons",
    "//code/utilities/keyboard/F310_gamepad/data:f310_gamepads",
    "//code/utilities/data_structures/color:rgb_color",
    "@sfml//:sfml",
])

hcp(name = "game_state_getter", deps = [
    "//code/utilities/keyboard/joycons:joycons",
    "//code/tools/games/crossword/state:game_state",
])
