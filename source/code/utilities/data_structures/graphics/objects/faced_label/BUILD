package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")
load("//bazel/rules/hcp:hcp_and_hcp_pos_hdrs_derive.bzl", "hcp_and_hcp_pos_hdrs_derive")

hcp_hdrs_derive(
    name = "faced_label_converter",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_is_active",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_is_enabled",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_set_active",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_cursor",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_set_enabled",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_cursor",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_first_name",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_cursor",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_message",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_set_cursor",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_set_cursor",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_set_first_name",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_drawer",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label:label_dimension_getter",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_eventer",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label:label_apply_events",
        "//code/utilities/data_structures/graphics/objects/label:label_dimension_getter",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_is_mouse_over",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label:label_dimension_getter",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label:label_is_mouse_over",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_highlight_text",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/cursor:label_cursor_action_doer",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/peripheral/pc:pc_input_state",
    ],
)

hcp_hdrs_derive(
    name = "faced_label_dimension_getter",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label/data:faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label/data:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label:label_dimension_getter",
    ],
)
