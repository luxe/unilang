package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_cursor_selection", deps = [
"//code/utilities/data_structures/position:position",
"//code/utilities/data_structures/graphics/objects/cursor:label_cursor",
])

hcp(name="label_cursor_mover", deps = [
"//code/utilities/fonts/bdf/settings:character_segment",
"//code/utilities/data_structures/graphics/objects/label:label_settings",
"//code/utilities/data_structures/graphics/objects/cursor:label_cursor_selection",
"//code/utilities/data_structures/graphics/text:str_to_bdf_segments",
"//code/utilities/fonts/bdf/character_maps:character_maps",
])

hcp(name="cursor",deps = [
"//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
])

hcp(name="label_cursor", deps = [
    "//code/utilities/data_structures/graphics/objects/cursor:cursor"
])

hcp(name="cursor_drawer", deps = [
    "//code/tools/ide/settings:ide_settings",
    "//code/utilities/data_structures/graphics/objects:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/peripheral/pc:pc_input_state",
    "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_selection_drawer",
    "//code/utilities/peripheral/mouse/state:mouse_position_getter",
    "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
    "//code/utilities/graphics/imgui/window:window_position_finder",
    "//code/tools/ide/frame:label_cursor_action_doer",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/data_structures/graphics/objects/mouse/draw:mouse_frame_getter",
])
