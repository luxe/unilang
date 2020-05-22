package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(
    name = "puyo",
    data = ["@PuyoPuyoAssets//:all"],
    deps = [],
)

hcp(
    name = "english_sounds",
    data = ["@english_sounds//:all"],
    deps = [],
)
