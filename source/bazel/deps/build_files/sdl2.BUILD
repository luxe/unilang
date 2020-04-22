package(default_visibility = ["//visibility:public"])
#load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

# Common include paths
sdl_includes = [
    "include",
    "src/video/x11",
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
    ],
)

# just the headers
cc_library(
    name = "SDL2_includes",
    hdrs = glob(["include/**/*.h"]),
    includes = sdl_includes,
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SDL2",
    hdrs = glob(["include/**/*.h"]),
    textual_hdrs = glob(["src/thread/generic/*.c"]),
    srcs = sdl_srcs,
    linkopts = ["-lSDL2"],
    visibility = ["//visibility:public"],
    deps = [":SDL2_includes"]
)