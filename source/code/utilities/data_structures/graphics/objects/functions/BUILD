package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="grid_label_drawer", deps = [
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
    "//code/utilities/data_structures/graphics/objects/faced_label:positioned_faced_label",
    "//code/utilities/data_structures/graphics/objects/label:label_drawer",
    "//code/utilities/data_structures/graphics/objects/grid:positioned_face_grid",
    "//code/utilities/data_structures/graphics/objects:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/peripheral/pc:pc_input_state",
])

hcp(name="tree_label_drawer", deps = [
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
    "//code/utilities/data_structures/graphics/objects/faced_label:positioned_faced_label",
    "//code/utilities/data_structures/graphics/objects/label:label_drawer",
    "//code/utilities/data_structures/graphics/objects/grid:positioned_face_tree",
    "//code/utilities/data_structures/graphics/objects/grid:face_tree",
    "//code/utilities/data_structures/graphics/objects:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/peripheral/pc:pc_input_state",
])

hcp(name="button_tree_label_drawer", deps = [
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
    "//code/utilities/data_structures/graphics/objects/grid/faced:positioned_buttoned_faced_label",
    "//code/utilities/data_structures/graphics/objects/label:label_drawer",
    "//code/utilities/data_structures/graphics/objects/grid:positioned_button_face_tree",
    "//code/utilities/data_structures/graphics/objects:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/peripheral/pc:pc_input_state",
    "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/data_structures/graphics/bitmap/premade:vertical_line",
    "//code/utilities/data_structures/graphics/bitmap/premade:horizontal_line",
    "//code/utilities/data_structures/graphics/bitmap/premade:l_line",
    "//code/utilities/data_structures/counters/unique_max_counter:unique_max_counter",
])
