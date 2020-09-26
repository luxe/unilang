package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "f310_gamepads_state_getter",
    deps = [
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepads",
        "@sfml",
    ],
)

enum_cpp(
    name = "f310_event",
    values = [
        "center_start_clicked",
        "center_start_held",
        "center_start_released",
        "center_back_clicked",
        "center_back_held",
        "center_back_released",
        "center_center_clicked",
        "center_center_held",
        "center_center_released",
        "arrows_up_clicked",
        "arrows_up_held",
        "arrows_up_released",
        "arrows_down_clicked",
        "arrows_down_held",
        "arrows_down_released",
        "arrows_left_clicked",
        "arrows_left_held",
        "arrows_left_released",
        "arrows_right_clicked",
        "arrows_right_held",
        "arrows_right_released",
        "buttons_up_clicked",
        "buttons_up_held",
        "buttons_up_released",
        "buttons_down_clicked",
        "buttons_down_held",
        "buttons_down_released",
        "buttons_left_clicked",
        "buttons_left_held",
        "buttons_left_released",
        "buttons_right_clicked",
        "buttons_right_held",
        "buttons_right_released",
    ],
)
#etc...

hcp(
    name = "f310_event_synthesizer",
    deps = [
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_events",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepad_phases",
        "//code/utilities/peripheral/keyboard/F310_gamepad/data:f310_gamepads_phases",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_event",
        "@sfml",
    ],
)
