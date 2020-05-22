package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "window_settings",
    deps = [
        "//code/utilities/graphics/imgui/window:menu_properties",
        "//code/utilities/graphics/imgui/window:window_position",
        "//code/utilities/graphics/imgui/window:window_size",
    ],
)

hcp(
    name = "menu_properties",
    deps = [
    ],
)

hcp(
    name = "window_position",
    deps = [
        "@imgui//:imgui_sdl_opengl3",
    ],
)

hcp(
    name = "window_size",
    deps = [
        "@imgui//:imgui_sdl_opengl3",
    ],
)

hcp(
    name = "window_renderer",
    deps = [
        "//code/utilities/graphics/imgui/window:window_settings",
        "@imgui//:imgui_sdl_opengl3",
    ],
)

hcp(
    name = "window_position_finder",
    deps = [
        "//code/utilities/data_structures/position",
        "@imgui//:imgui_sdl_opengl3",
    ],
)
