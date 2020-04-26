package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_drawer", deps = [
    "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:full_color_bitmap",
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/cursor:label_cursor_selection",
    "//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
    "//code/utilities/graphics/imgui/ui/draw/rectangle:rectangle_drawer",
    "//code/utilities/graphics/imgui/ui:ui_renders",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:full_color_bitmap_drawer",
    "//code/utilities/graphics/imgui/ui/draw/text:text_to_bitmap",
    "//code/utilities/graphics/imgui/ui/draw/text:str_to_bdf_segments",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/graphics/imgui/time:cycle_clock_checker",
    "//code/utilities/graphics/imgui/ui/draw/label/functions:label_text_bitmap_getter",
    "//code/utilities/graphics/imgui/ui/draw/label/style:label_style_chooser",
    "//code/utilities/graphics/imgui/ui/draw/label/functions:label_length_getter",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:positioned_label",
    "//code/tools/ide/frame/logic:frame_elements",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:positioned_full_color_bitmap",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/data_structures/dimensions:two_d_dimensions",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/graphics/imgui/ui/draw/label/functions:cursor_drawer",
])

hcp(name="faced_label_drawer", deps = [
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced:positioned_faced_label",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced:faced_label",
    "//code/utilities/graphics/imgui/ui/draw/label/functions:label_drawer",
    "//code/tools/ide/frame/logic:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
])

hcp(name="label_text_bitmap_getter", deps = [
    "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:full_color_bitmap",
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/draw/text:str_to_bdf_segments",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/graphics/imgui/time:cycle_clock_checker",
    "//code/utilities/graphics/imgui/ui/draw/text:text_to_bitmap",
    "//code/utilities/graphics/imgui/ui/draw/label/style:label_style_chooser",
    "//code/utilities/graphics/imgui/ui/draw/label/functions:label_length_getter",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
])

hcp(name="grid_label_drawer", deps = [
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced:positioned_faced_label",
    "//code/utilities/graphics/imgui/ui/draw/label/functions:label_drawer",
    "//code/utilities/graphics/imgui/ui/draw/label/grid:positioned_face_grid",
    "//code/tools/ide/frame/logic:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/graphics/imgui/ui/draw/label/functions:faced_label_drawer",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/peripheral/pc:pc_input_state",
])

hcp(name="label_length_getter", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
])

hcp(name="cursor_drawer", deps = [
    "//code/tools/ide/settings:ide_settings",
    "//code/tools/ide/frame/logic:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/peripheral/pc:pc_input_state",
    "//code/tools/ide/frame:mouse_selection_drawer",
    "//code/utilities/peripheral/mouse/state:mouse_position_getter",
    "//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
    "//code/utilities/graphics/imgui/ui/window:window_position_finder",
    "//code/tools/ide/frame:label_cursor_action_doer",
    "//code/utilities/types/vectors/operators:lib",
    "//code/tools/ide/frame:mouse_frame_getter",
])