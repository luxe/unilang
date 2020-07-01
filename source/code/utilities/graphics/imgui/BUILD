package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "mechanics",
    deps = [
        "@imgui//:imgui_sdl_opengl3",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "//code/utilities/graphics/sdl:sdl_window_creator",
        "//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/graphics/sdl:sdl_initializer",
        "@GL",
    ],
)

hcp(
    name = "ui_renders",
    deps = [
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
        "//code/utilities/filesystem/paths:lib",
        "@imgui//:imgui_sdl_opengl3",
        "@GL",
    ],
)

hcp(
    name = "imgui_type_utility",
    deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/position",
        "//code/utilities/graphics/imgui:mechanics",
        "@GL",
    ],
)
