package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "mouse_events",
    interface_deps = [
        "//code/utilities/data_structures/position",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)

hcp_hdrs_derive(
    name = "mouse_events_checker",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)
