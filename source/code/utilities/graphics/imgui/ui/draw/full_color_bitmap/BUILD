package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="full_color_bitmap", deps = [
"//code/utilities/graphics/imgui/ui/draw:color",
"//code/utilities/graphics/imgui/ui/draw:position",
])

hcp(name="full_color_bitmap_drawer", deps = [
"//code/utilities/graphics/imgui/ui/draw/full_color_bitmap:full_color_bitmap",
"//code/utilities/graphics/imgui/ui/draw/pixel:pixel_settings",
"//code/utilities/graphics/imgui/ui/draw/pixel:pixel_drawer",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events",
"//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
"//code/utilities/graphics/imgui/ui/draw:imgui_type_utility",
"//code/utilities/graphics/imgui/ui/draw:position",
"//code/utilities/graphics/imgui:mechanics",
])