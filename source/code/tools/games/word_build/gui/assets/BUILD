package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "assets", deps = [
    "@sfml//:sfml",
    "//code/tools/games/word_build/gui/assets:user_assets",
    "//code/utilities/peripheral/sound/sfml:sound",
    "//code/utilities/graphics/sfml/data:moving_text",
])

hcp(name = "assets_loader", deps = [
    "@sfml//:sfml",
    "//code/tools/games/word_build/gui/assets:assets",
    "//code/utilities/peripheral/sound/sfml:sound_loader",
    "//code/utilities/fonts/font_files:droid_sans_mono",
    "//code/tools/games/word_build/gui/state:game_state",
    "//code/utilities/assets:puyo",
    "//code/utilities/fonts/sfml:font_loader",
])

hcp(name = "user_assets", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/sound/sfml:sound",
])

