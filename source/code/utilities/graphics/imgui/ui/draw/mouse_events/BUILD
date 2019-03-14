package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="mouse_events",deps = [
"//code/utilities/graphics/imgui/ui/draw:position"
])

hcp(name="mouse_events_checker", deps = [
"//code/utilities/graphics/imgui/ui/draw/rectangle:rectangle_settings",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events",
"//code/utilities/graphics/imgui/ui/draw:position",
"//code/utilities/graphics/imgui:mechanics",
])