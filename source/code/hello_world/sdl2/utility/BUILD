load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)


cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "@GL",
        "@sdl2//:sdl2_hdrs",
        "@SDL_image//:hdrs",
        "@system//:SDL2",
        "@system//:SDL2_image",
        
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "//code/utilities/graphics/sdl:sdl_window_creator",
        "//code/utilities/graphics/sdl:sdl_initializer",
    ],
)
