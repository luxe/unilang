package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="line_settings",deps = [
    "//code/utilities/graphics/imgui/ui/draw:color",
    "//code/utilities/graphics/imgui/ui/draw:position"
])


hcp(name="line_drawer",deps = [
    "//code/utilities/graphics/imgui/ui/draw/line:line_settings",
    "//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events",
    "//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
    "//code/utilities/graphics/imgui/ui/draw:imgui_type_utility",
    "//code/utilities/graphics/imgui/ui/draw:position",
    "//code/utilities/graphics/imgui:mechanics",
])