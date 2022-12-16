package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "sound",
    interface_deps = [
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "sound_loader",
    interface_deps = [
        "//code/utilities/peripheral/sound/sfml:sound",
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "music_loader",
    interface_deps = [
        "//code/utilities/deps/external/sfml:lib",
    ],
)
