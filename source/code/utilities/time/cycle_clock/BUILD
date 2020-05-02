package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name="cycle_clock")

hcp(name="cycle_clock_checker", deps = [
"//code/utilities/time/cycle_clock:cycle_clock",
"@imgui//:imgui_sdl_opengl3",
])