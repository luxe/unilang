package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")

hcp(name = "assets", deps = [
    "@sfml//:sfml",
])

hcp(name = "assets_loader", deps = [
    "@sfml//:sfml",
    "//code/tools/games/ily3000/assets:assets",
])
