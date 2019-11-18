package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name="sdl_window_settings")

enum_cpp(name = "sdl_swap_interval",
values = 
["immediate"
,"synchronized_vertical_retrace"
,"adaptive_vsync"
])

hcp(name="sdl_init_settings",deps = [
    "//code/utilities/graphics/imgui/sdl:sdl_window_settings",
    "//code/utilities/graphics/imgui/sdl:sdl_swap_interval",
])
