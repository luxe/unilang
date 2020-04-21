package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_style", deps = [
    "//code/utilities/data_structures/color:transparent_rgb_color",
    "//code/utilities/data_structures/shapes/rectangle:rectangle_shade_colors",
    "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/style:label_width_style",
])

hcp(name="label_styles", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label/style:label_style",
])

hcp(name="label_width_style", deps = [
"//code/utilities/graphics/imgui/ui/draw/bitmap/pixel:pixel_slider",
])


hcp(name="label_style_chooser", deps = [
"//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
])


hcp(name="default_label_styles", deps = [
    "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:full_color_bitmap",
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/tools/ide/settings:ide_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
    "//code/utilities/graphics/imgui/ui/draw/rectangle:rectangle_drawer",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:full_color_bitmap_drawer",
    "//code/utilities/graphics/imgui/ui/draw/text:text_to_bitmap",
    "//code/utilities/graphics/imgui/ui:ui_renders",
    "//code/tools/transcompilers/unilang/tokens:get_tokens",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/pixel:pixel_slider",
    "//code/utilities/colors:rectangle_shades",
])
