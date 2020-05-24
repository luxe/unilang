load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    #deps = ["@SDL2"],
    deps = ["@sdl2//:SDL2"],
    linkopts = [
        "-lX11",
        "-lGL",
        "-lXaw",
        "-lXaw7",
        "-lXt",
    ],
)

cpp_main(
    name = "arrows",
    #deps = ["@SDL2"],
    deps = ["@sdl2//:SDL2"],
)
