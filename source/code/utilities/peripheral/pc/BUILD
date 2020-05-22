package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(
    name = "pc_input_state",
    deps = [
        "//code/utilities/peripheral/keyboard/state:keyboard_state",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)

hcp(
    name = "pc_input_state_getter",
    deps = [
        "//code/utilities/peripheral/keyboard/state:imgui_keyboard_state_getter",
        "//code/utilities/peripheral/mouse/state:mouse_state_getter",
        "//code/utilities/peripheral/pc:pc_input_state",
    ],
)
