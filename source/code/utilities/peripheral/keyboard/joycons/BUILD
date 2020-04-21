package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "joycon_horizontal_state", deps = [
    "//code/utilities/peripheral/keyboard/joycons:joycon_joystick",
])

hcp(name = "joycon_joystick", deps = [
])

hcp(name = "joycons", deps = [
    "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
])

hcp(name = "joycon_state_getter", deps = [
    "//code/utilities/peripheral/keyboard/joycons:joycons",
])

hcp(name = "joycon_joystick_direction_getter", deps = [
    "//code/utilities/peripheral/keyboard/joycons:joycons",
    "//code/utilities/data_structures:compass_direction_diagnonal",
])

hcp(name = "joystick_rotating_checker", deps = [
    "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/data_structures:compass_direction_diagnonal",
    "//code/utilities/peripheral/keyboard/joycons:joycon_joystick_direction_getter",
])