load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = ["@imgui//:imgui_sdl_opengl3",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/graphics/imgui:sdl_init_settings",
    ],
)
