package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "ui_renders",
    deps = [
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
        "//code/utilities/filesystem/paths:lib",
        "@GL",
        "@imgui//:imgui_sdl_opengl3",
    ],
)

hcp(
    name = "imgui_type_utility",
    deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/position",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "@GL",
    ],
)
