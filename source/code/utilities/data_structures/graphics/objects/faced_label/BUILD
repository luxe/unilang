package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp(
    name = "label_face",
    deps = [
        "//code/utilities/data_structures/graphics/objects/label:label_settings",
    ],
)

hcp_and_hcp_pos(
    name = "faced_label",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label:label_face",
    ],
)

hcp(
    name = "faced_label_converter",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label:positioned_faced_label",
    ],
)

hcp(
    name = "faced_label_is_active",
    deps = [
        "//code/utilities/data_structures/graphics/objects/faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label:positioned_faced_label",
    ],
)

hcp(
    name = "faced_label_drawer",
    deps = [
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/data_structures/graphics/objects/faced_label",
        "//code/utilities/data_structures/graphics/objects/faced_label:positioned_faced_label",
        "//code/utilities/data_structures/graphics/objects/label:label_drawer",
        "//code/utilities/data_structures/graphics/objects/label:label_settings",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/peripheral/mouse/state:mouse_state",
    ],
)
