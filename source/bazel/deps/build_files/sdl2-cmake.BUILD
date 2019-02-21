package(default_visibility = ["//visibility:public"])
load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

# Common include paths
sdl_includes = [
    "include",
    "src/video/khronos",
]

sdl_srcs = glob(
    include = [
        "src/**/*.c",
        "src/**/*.h",
    ],
    exclude = [
        "src/video/qnx/**",
        "src/haptic/windows/**",
        "src/test/*.c",
        "src/thread/generic/*.c",
        "src/core/linux/*.c",
    ],
)

cc_library(
    name = "SDL2",
    hdrs = glob(["include/**/*.h"]),
    includes = sdl_includes,
    srcs = sdl_srcs,
    #linkopts = ["-lSDL2"],
    visibility = ["//visibility:public"],
)