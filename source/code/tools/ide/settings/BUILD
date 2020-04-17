package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="ide_settings", deps = [
    "//code/utilities/data_structures/color:transparent_rgb_color",
    "//code/utilities/data_structures/position:position",
    "//code/utilities/graphics/imgui/ui/draw:cursor",
    "//code/utilities/graphics/imgui/ui/draw:mouse_selection",
    "//code/utilities/graphics/imgui/ui/draw:cursor_mouse_connector",
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/sdl:sdl_init_settings",
    "//code/tools/transcompilers/unilang/tokens:get_tokens",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/window:window_settings",
    "//code/tools/ide/settings:background_settings",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/multi_color_bitmap:multi_color_bitmap",
    "//code/tools/ide/settings:mouse",
    "//code/tools/ide/settings:label_cursor",
    "//code/utilities/data_structures/shapes/rectangle:shade_rectangle_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:positioned_label",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced:positioned_faced_label",
])

hcp(name="background_settings", deps = [
    "//code/utilities/data_structures/color:transparent_rgb_color",
    "//code/utilities/data_structures/position:position",
    "//code/utilities/graphics/imgui/ui/draw:cursor",
    "//code/utilities/graphics/imgui/ui/draw:mouse_selection",
    "//code/utilities/graphics/imgui/ui/draw:cursor_mouse_connector",
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/sdl:sdl_init_settings",
    "//code/tools/transcompilers/unilang/tokens:get_tokens",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/window:window_settings",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/multi_color_bitmap:multi_color_bitmap",
    "//code/utilities/data_structures/shapes/rectangle:positioned_rectangle_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/grid:positioned_face_grid",
])

hcp(name="ide_settings_getter", deps = [
    "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:full_color_bitmap",
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/draw/mouse_events:mouse_events_checker",
    "//code/utilities/graphics/imgui/ui/draw/rectangle:rectangle_drawer",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/full_color_bitmap:full_color_bitmap_drawer",
    "//code/utilities/graphics/imgui/ui/draw/text:text_to_bitmap",
    "//code/utilities/graphics/imgui/ui:ui_renders",
    "//code/tools/transcompilers/unilang/tokens:get_tokens",
    "//code/tools/ide/settings:ide_settings",
    "//code/tools/transcompilers/unilang/language-and-theme-creator/font:unilang_font",
    "//code/tools/ide/settings:standard_bitmap_cursor",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/pixel:pixel_slider",
    "//code/utilities/colors:rectangle_shades",
    "//code/utilities/graphics/imgui/ui/draw/label/style:default_label_styles",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced:faced_label_converter",
])

hcp(name="standard_bitmap_cursor", deps = [
    "//code/utilities/graphics/imgui/ui/draw/bitmap/multi_color_bitmap:multi_color_bitmap",
])

hcp(name="mouse", deps = [
    "//code/utilities/graphics/imgui/ui/draw:mouse_selection",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
])

hcp(name="label_cursor", deps = [
    "//code/utilities/graphics/imgui/ui/draw:cursor"
])