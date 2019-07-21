package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "x11_looper", deps = [
    "//code/utilities/x11/data:main_x11_state",
    "//code/utilities/x11/data:x11_window_geometry",
    "//code/utilities/x11/data:x11_bg_fg_colors",
    "//code/utilities/time/sleeping:lib",
])