package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(name = "textured_sprite", deps = [
    "@sfml//:sfml"
])

hcp(name = "assets", deps = [
    "//code/tools/math_game/assets:textured_sprite"
])

hcp(name = "assets_loader", deps = [
    "@sfml//:sfml",
    "//code/tools/math_game/assets:assets",
])
