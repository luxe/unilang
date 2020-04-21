package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name="window_settings",deps = [
    "//code/utilities/graphics/imgui/ui/window:menu_properties",
    "//code/utilities/graphics/imgui/ui/window:window_position",
    "//code/utilities/graphics/imgui/ui/window:window_size",
])


hcp(name="menu_properties",deps = [
])

hcp(name="window_position",deps = [
"@imgui//:imgui_sdl_opengl3"
])

hcp(name="window_size",deps = [
"@imgui//:imgui_sdl_opengl3"
])

hcp(name="window_renderer",deps = [
"@imgui//:imgui_sdl_opengl3",
"//code/utilities/graphics/imgui/ui/window:window_settings"
])

hcp(name="window_position_finder",deps = [
"//code/utilities/data_structures/position:position",
"@imgui//:imgui_sdl_opengl3",
])