package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(
    name = "mouse_controller",
    deps = [
        "//code/utilities/data_structures/point",
        "//code/utilities/graphics/x11/xdo:lib",
        "//code/utilities/random:lib",
        "//code/utilities/time/sleeping:lib",
    ],
)

hcp(
    name = "mouse_resizer",
    deps = [
        "//code/utilities/language_basic/control_structures/looping:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/converting:lib",
    ],
)

cpp_main(
    name = "cycle_mouse",
    deps = [
        "//code/utilities/peripheral/mouse:mouse_resizer",
    ],
)
