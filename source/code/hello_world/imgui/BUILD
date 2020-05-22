load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = [
        "//code/utilities/graphics/imgui:mechanics",
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "@imgui//:imgui_sdl_opengl3",
    ],
)
