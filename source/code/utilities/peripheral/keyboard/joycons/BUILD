package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "joycon_horizontal_state",
    deps = [
        "//code/utilities/peripheral/keyboard/joycons:joycon_joystick",
    ],
)

hcp(
    name = "joycon_joystick",
    deps = [
    ],
)

hcp(
    name = "joycons",
    deps = [
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    ],
)

hcp(
    name = "joycon_state_getter",
    deps = [
        "//code/utilities/peripheral/keyboard/joycons",
        "@sfml",
    ],
)

hcp(
    name = "joycon_joystick_direction_getter",
    deps = [
        "//code/utilities/data_structures:compass_direction_diagnonal",
        "//code/utilities/peripheral/keyboard/joycons",
        "@sfml",
    ],
)

hcp(
    name = "joystick_rotating_checker",
    deps = [
        "//code/utilities/data_structures:compass_direction_diagnonal",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_joystick_direction_getter",
        "@sfml",
    ],
)
