package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "system_sound_adjuster",
    interface_deps = [
        "//code/utilities/program/call:lib",
    ],
)

hcp_hdrs_derive(
    name = "music_player",
    interface_deps = [
        "//code/utilities/deps/external/sdl2:lib"
    ],
)
