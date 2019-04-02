package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_settings", deps = [
"//code/utilities/graphics/imgui/ui/draw:color",
"//code/utilities/graphics/imgui/ui/draw:position",
"//code/utilities/graphics/imgui/ui/draw/rectangle:rectangle_settings",
"//code/utilities/graphics/imgui/ui/draw/label:label_cursor_selection",
"//code/utilities/graphics/imgui/ui/draw/label:label_styles",
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
])

hcp(name="label_cursor_selection", deps = [
"//code/utilities/graphics/imgui/ui/draw:position",
])

hcp(name="label_style", deps = [
    "//code/utilities/graphics/imgui/ui/draw:color",
    "//code/utilities/graphics/imgui/ui/draw/rectangle:rectangle_settings",
    "//code/utilities/graphics/imgui/ui/draw/label:label_width_style",
])

hcp(name="label_styles", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label:label_style",
])

hcp(name="label_user_state", deps = [
])

hcp(name="label_width_style", deps = [
"//code/utilities/graphics/imgui/ui/draw/bitmap/pixel:pixel_slider",
])

hcp(name="label_cursor_mover", deps = [
"//code/utilities/bdf/settings:character_segment",
"//code/utilities/graphics/imgui/ui/draw/label:label_settings",
"//code/utilities/graphics/imgui/ui/draw/label:label_cursor_selection",
"//code/utilities/graphics/imgui/ui/draw/text:str_to_bdf_segments",
])