package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_settings", deps = [
"//code/utilities/data_structures/color:transparent_rgb_color",
"//code/utilities/data_structures/position:position",
"//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
"//code/utilities/graphics/imgui/ui/draw/label:label_cursor_selection",
"//code/utilities/graphics/imgui/ui/draw/label/style:label_styles",
"//code/utilities/graphics/imgui/ui/draw/label:label_user_state",
])

hcp(name="label_drawer", deps = [
    "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:full_color_bitmap",
    "//code/utilities/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/ui/draw/label:label_settings",
    "//code/utilities/graphics/imgui/ui/draw/label:label_cursor_selection",
    "//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
    "//code/utilities/graphics/imgui/ui/draw/rectangle:rectangle_drawer",
    "//code/utilities/graphics/imgui/ui:ui_renders",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:full_color_bitmap_drawer",
    "//code/utilities/graphics/imgui/ui/draw/text:text_to_bitmap",
    "//code/utilities/graphics/imgui/ui/draw/text:str_to_bdf_segments",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/graphics/imgui/time:cycle_clock_checker",
    "//code/utilities/graphics/imgui/ui/draw/label:label_text_bitmap_getter",
    "//code/utilities/graphics/imgui/ui/draw/label/style:label_style_chooser",
])

hcp(name="label_cursor_selection", deps = [
"//code/utilities/data_structures/position:position",
])

hcp(name="label_user_state", deps = [
])

hcp(name="label_cursor_mover", deps = [
"//code/utilities/bdf/settings:character_segment",
"//code/utilities/graphics/imgui/ui/draw/label:label_settings",
"//code/utilities/graphics/imgui/ui/draw/label:label_cursor_selection",
"//code/utilities/graphics/imgui/ui/draw/text:str_to_bdf_segments",
])




hcp(name="label_text_bitmap_getter", deps = [
"//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:full_color_bitmap",
"//code/utilities/bdf/settings:character_segment",
"//code/utilities/graphics/imgui/ui/draw/label:label_settings",
"//code/utilities/graphics/imgui/ui/draw/text:str_to_bdf_segments",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/graphics/imgui/time:cycle_clock_checker",
"//code/utilities/graphics/imgui/ui/draw/text:text_to_bitmap",
"//code/utilities/graphics/imgui/ui/draw/label/style:label_style_chooser",
])