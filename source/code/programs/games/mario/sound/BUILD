package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp(
    name = "sound",
    deps = [
    ],
)

hcp(
    name = "sounds",
    deps = [
        "//code/programs/games/mario/sound",
    ],
)

hcp(
    name = "sounds_loader",
    deps = [
        "//code/programs/games/mario/sound:sounds",
    ],
)
