package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "global_event_listener",
    deps = [
        "//code/utilities/graphics/x11/data:main_x11_state",
        "@x11",
        "@xorg_xinput//:lib",
    ],
)
