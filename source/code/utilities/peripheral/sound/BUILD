package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "system_sound_adjuster",
    deps = [
        "//code/utilities/program/call:lib",
    ],
)

hcp(
    name = "music_player",
    deps = [
        #"@system//:SDL2",
        #"@system//:SDL2
        
        #"@SDL_mixer",
        #"@sdl2",
        "@sdl2",
        "@system//:SDL2_mixer",
        "@system//:SDL2_hdrs",
    ],
)
