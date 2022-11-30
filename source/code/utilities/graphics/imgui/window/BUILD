package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

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
        "//code/utilities/deps/external/imgui:lib",
    ],
)

hcp(
    name = "window_size",
    deps = [
        "//code/utilities/deps/external/imgui:lib",
    ],
)

hcp(
    name = "window_renderer",
    deps = [
        "//code/utilities/graphics/imgui/window:window_settings",
        "//code/utilities/deps/external/imgui:lib",
    ],
)

hcp(
    name = "window_position_finder",
    deps = [
        "//code/utilities/data_structures/position",
        "//code/utilities/deps/external/imgui:lib",
    ],
)
