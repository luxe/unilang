package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "f310_gamepad", deps = [
    "//code/utilities/keyboard/F310_gamepad/parts:joystick",
    "//code/utilities/keyboard/F310_gamepad/parts:left_arrows",
    "//code/utilities/keyboard/F310_gamepad/parts:center_buttons",
    "//code/utilities/keyboard/F310_gamepad/parts:top_buttons",
])