package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp_hdrs_derive(
    name = "assets",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "assets_loader",
    interface_deps = [
        "//code/programs/games/filler/gui/assets",
        "//code/programs/games/filler/gui/state:game_state",
    ],
)