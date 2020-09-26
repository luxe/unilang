package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "cycle_clock")

hcp(
    name = "cycle_clock_checker",
    deps = [
        "//code/utilities/time/cycle_clock",
        "@imgui//:imgui_sdl_opengl3",
    ],
)
