package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="pixel_settings", deps = [
"//code/utilities/graphics/imgui/ui/draw:color",
"//code/utilities/data_structures/position:position",
])

hcp(name="pixel_drawer", deps = [
"//code/utilities/graphics/imgui/ui/draw/bitmap/pixel:pixel_settings",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
"//code/utilities/graphics/imgui/ui/draw:imgui_type_utility",
"//code/utilities/data_structures/position:position",
"//code/utilities/graphics/imgui:mechanics",
])

hcp(name="pixel_slider", deps = [
"//code/utilities/graphics/imgui/time:cycle_clock",
])