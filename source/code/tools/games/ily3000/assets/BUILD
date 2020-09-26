package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "assets",
    deps = [
        "@sfml",
    ],
)

hcp(
    name = "assets_loader",
    deps = [
        "//code/tools/games/ily3000/assets",
        "@sfml",
    ],
)
