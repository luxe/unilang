package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "background_settings",
    deps = [
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
        "//code/utilities/graphics/imgui/window:window_settings",
    ],
)

hcp(
    name = "background_settings_getter",
    deps = [
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/graphics/imgui:imgui_type_utility",
        "//code/utilities/graphics/imgui/background:background_settings",
    ],
)
