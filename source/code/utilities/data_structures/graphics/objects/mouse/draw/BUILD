package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "mouse_frame_getter",
    interface_deps = [
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_selection_drawer",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/graphics/imgui/window:window_position_finder",
        "//code/utilities/peripheral/mouse/state:mouse_position_getter",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/data_structures/graphics/text:text_to_bitmap",
    ],
)

hcp_hdrs_derive(
    name = "mouse_selection_drawer",
    interface_deps = [
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/mouse/state:mouse_state_getter",
    ],
)

hcp_hdrs_derive(
    name = "view_anchor_adjuster",
    interface_deps = [
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/mouse:anchor_mouse",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/peripheral/mouse/state:mouse_state",
        "//code/utilities/peripheral/mouse/state:mouse_state_getter",
    ],
)
