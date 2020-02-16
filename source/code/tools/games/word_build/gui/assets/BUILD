package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "assets", deps = [
    "@sfml//:sfml",
    "//code/tools/games/word_build/gui/assets:user_assets",
    "//code/utilities/peripheral/sound/sfml:sound",
])

hcp(name = "assets_loader", deps = [
    "@sfml//:sfml",
    "//code/tools/games/word_build/gui/assets:assets",
    "//code/utilities/peripheral/sound/sfml:sound_loader",
])

hcp(name = "user_assets", deps = [
    "@sfml//:sfml",
    "//code/utilities/peripheral/sound/sfml:sound",
])

