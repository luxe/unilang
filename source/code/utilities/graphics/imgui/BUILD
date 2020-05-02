package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name="mechanics",deps = [
    "//code/utilities/graphics/sdl:sdl_init_settings",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/graphics/sfml:game_loop",
    "@imgui//:imgui_sdl_opengl3"
])

hcp(name="ui_renders",deps = [
    "@imgui//:imgui_sdl_opengl3",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/data_structures/shapes/rectangle:rectangle_settings"
])

hcp(name="imgui_type_utility", deps = [
"//code/utilities/data_structures/color:transparent_rgb_color",
"//code/utilities/data_structures/position:position",
"//code/utilities/graphics/imgui:mechanics",
])
