package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "assets", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/sound/sfml:sound",
    "//code/utilities/graphics/sfml/data:moving_text",
])

hcp(name = "assets_loader", deps = [
    "@sfml//:sfml",
    "//code/tools/games/ur/gui/assets:assets",
    "//code/utilities/peripheral/sound/sfml:sound_loader",
    "//code/utilities/fonts/font_files:droid_sans_mono",
    "//code/tools/games/ur/gui/state:game_state",
])
