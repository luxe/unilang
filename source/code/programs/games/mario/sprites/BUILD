package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp(
    name = "sprites",
    deps = [
        "//code/utilities/graphics/x11/sprite",
    ],
)

hcp(
    name = "sprites_loader",
    deps = [
        "//code/programs/games/mario/sprites",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/graphics/x11/sprite:sprite_loader",
    ],
)
