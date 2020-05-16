package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp_and_hcp_pos(name="face_tree", deps = [
    "//code/utilities/data_structures/graphics/objects/faced_label:faced_label",
    "//code/utilities/data_structures/line_break:should_line_break",
    "@tree//:tree"
])

hcp(name="tree_label_drawer", deps = [
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
    "//code/utilities/data_structures/graphics/objects/faced_label:positioned_faced_label",
    "//code/utilities/data_structures/graphics/objects/label:label_drawer",
    "//code/utilities/data_structures/graphics/objects/faced_tree:positioned_face_tree",
    "//code/utilities/data_structures/graphics/objects/faced_tree:face_tree",
    "//code/utilities/data_structures/graphics/objects:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/peripheral/pc:pc_input_state",
])
