package(default_visibility = ["//visibility:public"])

cc_library(
    name = "main",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
    linkopts = [],
    deps = [
        #"@SDL2",
        #"@opengl",
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
    includes = [
        ".",
        "examples",
        "examples/libs",
        "examples/libs/gl3w",
    ],
    deps = [
        ":main",
        "@sdl2",
    ],
)

cc_binary(
    name = "imgui_sdl_opengl3_main",
    srcs = ["examples/example_sdl_opengl3/main.cpp"],
    deps = [
        "@GL",
        ":imgui_sdl_opengl3",
    ]
)




cc_library(
    name = "imgui_sdl_opengl2",
    srcs = [
        "examples/imgui_impl_opengl2.cpp",
        "examples/imgui_impl_sdl.cpp",
        "examples/libs/gl3w/GL/gl3w.c",
    ],
    hdrs = [
        "examples/imgui_impl_opengl2.h",
        "examples/imgui_impl_sdl.h",
        "examples/libs/gl3w/GL/gl3w.h",
        "examples/libs/gl3w/GL/glcorearb.h",
    ],
    includes = [
        ".",
        "examples",
        "examples/libs",
        "examples/libs/gl3w",
    ],
    deps = [
        ":main",
        "@sdl2",
    ],
)

cc_binary(
    name = "imgui_sdl_opengl2_main",
    srcs = ["examples/example_sdl_opengl2/main.cpp"],
    deps = [
        "@GL",
        ":imgui_sdl_opengl2",
    ]
)