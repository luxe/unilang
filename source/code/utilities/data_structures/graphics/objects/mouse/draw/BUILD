package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "mouse_frame_getter",
    deps = [
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/tools/ide/settings:ide_settings",
        "//code/utilities/graphics/imgui/render:frame_elements",
        "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_selection_drawer",
        "//code/utilities/peripheral/mouse/state:mouse_position_getter",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/graphics/imgui/ui/window:window_position_finder",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(name = "mouse_selection_drawer", deps = [
    "@imgui//:imgui_sdl_opengl3",
    "//code/tools/ide/settings:ide_settings",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/graphics/imgui/render:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state_getter",
    "//code/utilities/peripheral/mouse/state:mouse_state",
])

hcp(name = "view_anchor_adjuster", deps = [
    "@imgui//:imgui_sdl_opengl3",
    "//code/tools/ide/settings:ide_settings",
    "//code/utilities/graphics/imgui:mechanics",
    "//code/utilities/graphics/imgui/render:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state_getter",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/data_structures/graphics/objects/mouse:anchor_mouse",
])
