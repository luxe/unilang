package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "joycon_horizontal_state",
    interface_deps = [
        "//code/utilities/peripheral/keyboard/joycons:joycon_joystick",
    ],
)

hcp_hdrs_derive(
    name = "joycon_joystick",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "joycons",
    interface_deps = [
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
    ],
)

hcp_hdrs_derive(
    name = "joycon_state_getter",
    interface_deps = [
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "joycon_joystick_direction_getter",
    interface_deps = [
        "//code/utilities/data_structures:compass_direction_diagnonal",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/deps/external/sfml:lib",
    ],
)

hcp_hdrs_derive(
    name = "joystick_rotating_checker",
    interface_deps = [
        "//code/utilities/data_structures:compass_direction_diagnonal",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_joystick_direction_getter",
        "//code/utilities/deps/external/sfml:lib",
    ],
)
