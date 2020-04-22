package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")

enum_cpp(name = "key_state",
values = [
"down"
,"pressed"
,"none"
])

hcp(name = "keyboard_state", deps = [
    "//code/utilities/peripheral/keyboard/state:key_state",
])

hcp(name = "imgui_keyboard_state_getter", deps = [
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/peripheral/keyboard/state:keyboard_state",
    "//code/utilities/peripheral/keyboard:key_detector",
])

