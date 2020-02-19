package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")



hcp(name = "sprites", deps = [
    "//code/utilities/x11/sprite:sprite",
])

hcp(name = "sprites_loader", deps = [
    "//code/tools/games/mario/sprites:sprites",
    "//code/utilities/x11/sprite:sprite_loader",
    "//code/utilities/x11/data:main_x11_state",
])