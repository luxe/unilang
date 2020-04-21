package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "key_detector", deps = [
    "@imgui//:imgui_sdl_opengl3",
    "//code/tools/ide/settings:ide_settings",
    "//code/utilities/graphics/imgui:mechanics",
])