package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "assets", deps = [
    "@sfml//:sfml",
])

hcp(name = "assets_loader", deps = [
    "@sfml//:sfml",
    "//code/tools/games/word_build/assets:assets",
])
