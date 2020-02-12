package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "game_state", deps = [
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepads",
    "//code/utilities/data_structures/color:rgb_color",
    "@sfml//:sfml",
])

hcp(name = "game_state_getter", deps = [
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/tools/games/word_build/gui/state:game_state",
])
