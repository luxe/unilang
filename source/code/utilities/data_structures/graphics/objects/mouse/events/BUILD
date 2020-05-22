package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "mouse_events",
    deps = [
        "//code/utilities/data_structures/position",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)

hcp(
    name = "mouse_events_checker",
    deps = [
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
        "//code/utilities/data_structures/position",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
        "//code/utilities/graphics/imgui:mechanics",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)
