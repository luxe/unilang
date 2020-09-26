package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "sound",
    deps = [
        "@sfml",
    ],
)

hcp(
    name = "sound_loader",
    deps = [
        "//code/utilities/peripheral/sound/sfml:sound",
        "@sfml",
    ],
)

hcp(
    name = "music_loader",
    deps = [
        "@sfml",
    ],
)
