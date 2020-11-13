package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp(
    name = "buttoned_faced_label_is_active",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:positioned_buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_is_active",
    ],
)

hcp(
    name = "buttoned_faced_label_toggle_button",
    deps = [
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:positioned_buttoned_faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_is_active",
    ],
)

hcp(
    name = "buttoned_faced_label_drawer",
    deps = [
        "//code/utilities/fonts/bdf/character_maps:character_maps",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label:absolute_button_maker",
    ],
)

hcp(
    name = "absolute_button_maker",
    deps = [
        "//code/utilities/fonts/bdf/character_maps:character_maps",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "buttoned_faced_label_is_mouse_over",
    deps = [
        "//code/utilities/fonts/bdf/character_maps:character_maps",
        "//code/utilities/data_structures/graphics/objects/buttoned_faced_label/data:buttoned_faced_label",
        "//code/utilities/peripheral/pc:pc_input_state",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)