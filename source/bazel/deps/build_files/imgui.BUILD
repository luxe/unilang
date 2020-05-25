package(default_visibility = ["//visibility:public"])

cc_library(
    name = "main",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
    linkopts = [],
    deps = [
        "@opengl",
        "@sdl2//:SDL2",
    ],
)

cc_library(
    name = "imgui_sdl_opengl3",
    srcs = [
        "examples/imgui_impl_opengl3.cpp",
        "examples/imgui_impl_sdl.cpp",
        "examples/libs/gl3w/GL/gl3w.c",
    ],
    hdrs = [
        "examples/imgui_impl_opengl3.h",
        "examples/imgui_impl_sdl.h",
        "examples/libs/gl3w/GL/gl3w.h",
        "examples/libs/gl3w/GL/glcorearb.h",
    ],
    copts = [],
    includes = [
        ".",
        "examples/libs",
        "examples/libs/gl3w",
    ],
    deps = [
        ":main",
    ],
)
