package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="color",deps = [])
hcp(name="rectangle_settings",deps = [
    "//code/utilities/graphics/imgui/ui/draw:color"
])
hcp(name="mouse_events",deps = [])
hcp(name="position",deps = [])

hcp(name="mouse_events_checker", deps = [
"//code/utilities/graphics/imgui/ui/draw:rectangle_settings",
"//code/utilities/graphics/imgui/ui/draw:mouse_events",
"//code/utilities/graphics/imgui/ui/draw:position",
"//code/utilities/graphics/imgui:mechanics",
])

hcp(name="rectangle_drawer", deps = [
"//code/utilities/graphics/imgui/ui/draw:rectangle_settings",
"//code/utilities/graphics/imgui/ui/draw:mouse_events",
"//code/utilities/graphics/imgui/ui/draw:mouse_events_checker",
"//code/utilities/graphics/imgui/ui/draw:imgui_type_utility",
"//code/utilities/graphics/imgui/ui/draw:position",
"//code/utilities/graphics/imgui:mechanics",
])

hcp(name="imgui_type_utility", deps = [
"//code/utilities/graphics/imgui/ui/draw:color",
"//code/utilities/graphics/imgui:mechanics",
])
