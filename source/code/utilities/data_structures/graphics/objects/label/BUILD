package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/hcp:hcp_pos.bzl", "hcp_pos")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_user_state", deps = [
])


hcp(name="label_settings", deps = [
"//code/utilities/data_structures/color:transparent_rgb_color",
"//code/utilities/data_structures/position:position",
"//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
"//code/utilities/data_structures/graphics/objects/cursor:label_cursor_selection",
"//code/utilities/data_structures/graphics/objects/label/style:label_styles",
"//code/utilities/data_structures/graphics/objects/label:label_user_state",
"//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events",
"//code/utilities/data_structures/graphics/objects/cursor:label_cursor",
])

hcp_pos(name="label", deps = [
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
])

hcp(name="label_drawer", deps = [
    "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:full_color_bitmap",
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
    "//code/utilities/data_structures/graphics/objects/cursor:label_cursor_selection",
    "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
    "//code/utilities/graphics/imgui/render/elements:rectangle_drawer",
    "//code/utilities/graphics/imgui:ui_renders",
    "//code/utilities/graphics/imgui/render/elements:full_color_bitmap_drawer",
    "//code/utilities/data_structures/graphics/text:text_to_bitmap",
    "//code/utilities/data_structures/graphics/text:str_to_bdf_segments",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/time/cycle_clock:cycle_clock_checker",
    "//code/utilities/data_structures/graphics/objects/label:label_text_bitmap_getter",
    "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    "//code/utilities/data_structures/graphics/objects/label:label_length_getter",
    "//code/utilities/data_structures/graphics/objects/label:positioned_label",
    "//code/utilities/data_structures/graphics/objects:frame_elements",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:positioned_full_color_bitmap",
    "//code/utilities/peripheral/mouse/state:mouse_state",
    "//code/utilities/data_structures/dimensions:two_d_dimensions",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/data_structures/graphics/objects/cursor:cursor_drawer",
    "//code/utilities/colors:color_defaults",
])

hcp(name="label_length_getter", deps = [
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
])

hcp(name="label_text_bitmap_getter", deps = [
    "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:full_color_bitmap",
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
    "//code/utilities/data_structures/graphics/text:str_to_bdf_segments",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/time/cycle_clock:cycle_clock_checker",
    "//code/utilities/data_structures/graphics/text:text_to_bitmap",
    "//code/utilities/data_structures/graphics/objects/label/style:label_style_chooser",
    "//code/utilities/data_structures/graphics/objects/label:label_length_getter",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
])
