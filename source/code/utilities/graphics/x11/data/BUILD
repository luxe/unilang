package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "x11_bg_fg_colors",
    deps = [
        "@x11",
    ],
)

hcp(
    name = "x11_window_geometry",
    deps = [
        "@x11",
    ],
)

hcp(
    name = "main_x11_state",
    deps = [
        ":x11_bg_fg_colors",
        ":x11_window_geometry",
        "@x11",
    ],
)
