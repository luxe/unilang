package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "assets", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/sound/sfml:sound",
    "//code/utilities/graphics/sfml/data:moving_text",
    "//code/utilities/graphics/sfml/data:named_rectangles",
    "//code/utilities/graphics/sfml/sprite:textured_sprite",
])

hcp(name = "assets_loader", deps = [
    "@sfml//:sfml",
    "//code/tools/games/ur/assets:assets",
    "//code/utilities/peripheral/sound/sfml:sound_loader",
    "//code/utilities/fonts/font_files:droid_sans_mono",
    "//code/tools/games/ur/state:game_state",
    "//code/utilities/graphics/sfml/sprite:textured_sprite_loader",
])
