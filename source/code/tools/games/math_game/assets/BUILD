package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")


hcp(name = "title_screen_assets", deps = [
    "//code/utilities/graphics/sfml/sprite:textured_sprite",
    "@sfml//:sfml",
])

hcp(name = "character_selection_assets", deps = [
    "//code/utilities/graphics/sfml/sprite:textured_sprite",
    "@sfml//:sfml",
])

hcp(name = "character", deps = [
    "//code/utilities/graphics/sfml/sprite:textured_sprite",
    "@sfml//:sfml",
])

hcp(name = "assets", deps = [
    "//code/utilities/graphics/sfml/sprite:textured_sprite",
    "//code/utilities/peripheral/sound/sfml:sound",
    "//code/tools/games/math_game/assets:title_screen_assets",
    "//code/tools/games/math_game/assets:character_selection_assets",
    "//code/tools/games/math_game/assets:character",
    "@sfml//:sfml",
])

hcp(name = "assets_loader", deps = [
    "@sfml//:sfml",
    "//code/tools/games/math_game/assets:assets",
    "//code/utilities/peripheral/sound/sfml:sound_loader",
    "//code/utilities/graphics/sfml/sprite:textured_sprite_loader",
    "//code/utilities/fonts/sfml:font_loader",
    "//code/utilities/peripheral/sound/sfml:music_loader",
])
