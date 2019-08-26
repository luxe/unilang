package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "textured_sprite", deps = [
    "@sfml//:sfml"
])

hcp(name = "sound", deps = [
    "@sfml//:sfml"
])

hcp(name = "title_screen_assets", deps = [
    "//code/tools/math_game/assets:textured_sprite",
    "//code/tools/math_game/assets:sound",
    "@sfml//:sfml",
])

hcp(name = "character_selection_assets", deps = [
    "//code/tools/math_game/assets:textured_sprite",
    "//code/tools/math_game/assets:sound",
    "@sfml//:sfml",
])

hcp(name = "assets", deps = [
    "//code/tools/math_game/assets:textured_sprite",
    "//code/tools/math_game/assets:sound",
    "//code/tools/math_game/assets:title_screen_assets",
    "//code/tools/math_game/assets:character_selection_assets",
    "@sfml//:sfml",
])

hcp(name = "assets_loader", deps = [
    "@sfml//:sfml",
    "//code/tools/math_game/assets:assets",
])
