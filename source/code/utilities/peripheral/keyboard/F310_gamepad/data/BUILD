package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "f310_gamepad",
    deps = [
        "//code/utilities/peripheral/keyboard/F310_gamepad/data/parts:center_buttons",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data/parts:joystick",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data/parts:left_arrows",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data/parts:top_buttons",
    ],
)

hcp(
    name = "f310_gamepads",
    deps = [
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepad",
    ],
)

hcp(
    name = "f310_gamepad_phases",
    deps = [
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepad",
    ],
)

hcp(
    name = "f310_gamepads_phases",
    deps = [
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepad_phases",
    ],
)

hcp(
    name = "f310_events",
    deps = [
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_event",
    ],
)
