package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "assets", deps = [
    "@sfml//:sfml",
    "//code/tools/games/word_build/gui/assets:user_assets",
])

hcp(name = "assets_loader", deps = [
    "@sfml//:sfml",
    "//code/tools/games/word_build/gui/assets:assets",
])

hcp(name = "user_assets", deps = [
    "@sfml//:sfml",
])

