package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
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
])

hcp(name="faced_label_drawer", deps = [
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced:positioned_faced_label",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced:faced_label",
    "//code/utilities/graphics/imgui/ui/draw/label/functions:label_drawer",
    "//code/tools/ide/frame/logic:frame_elements",
    "//code/utilities/peripheral/mouse/state:mouse_state",
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
])

hcp(name="label_length_getter", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
])