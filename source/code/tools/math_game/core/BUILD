package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "frame_renderer", deps = [
    "@sfml//:sfml",
    "//code/utilities/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/json/functions:lib",
    "//code/utilities/keyboard/joycons:joycons",
    "//code/utilities/keyboard/joycons:joycon_state_getter",
    "//code/tools/math_game/assets:assets_loader",
    "//code/tools/math_game/state:game_state",
])