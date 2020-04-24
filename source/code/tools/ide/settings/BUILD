package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="ide_settings", deps = [
    "//code/utilities/data_structures/color:transparent_rgb_color",
    "//code/utilities/data_structures/position:position",
    "//code/utilities/graphics/imgui/ui/draw/label/cursor:cursor",
    "//code/utilities/graphics/imgui/ui/draw/mouse:mouse_selection",
    "//code/utilities/graphics/imgui/ui/draw/mouse:cursor_mouse_connector",
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/imgui/sdl:sdl_init_settings",
    "//code/tools/transcompilers/unilang/tokens:get_tokens",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:label_settings",
    "//code/utilities/graphics/imgui/ui/window:window_settings",
    "//code/utilities/graphics/imgui/ui/draw/background:background_settings",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/multi_color_bitmap:multi_color_bitmap",
    "//code/utilities/graphics/imgui/ui/draw/mouse:mouse",
    "//code/utilities/graphics/imgui/ui/draw/label/cursor:label_cursor",
    "//code/utilities/data_structures/shapes/rectangle:shade_rectangle_settings",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced/regular:positioned_label",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced:positioned_faced_label",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
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
    "//code/utilities/graphics/imgui/ui/draw/bitmap/premade:crosshair_mouse",
    "//code/utilities/graphics/imgui/ui/draw/bitmap/pixel:pixel_slider",
    "//code/utilities/colors:rectangle_shades",
    "//code/utilities/graphics/imgui/ui/draw/label/style:default_label_styles",
    "//code/utilities/graphics/imgui/ui/draw/label/grid/faced:faced_label_converter",
    "//code/utilities/graphics/imgui/ui/draw/mouse/premade:standard_mouse",
    "//code/utilities/fonts/bdf/complete/unilang:unilang_segments",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/fonts/bdf/character_maps:character_maps_getter",
    "//code/utilities/graphics/imgui/ui/draw/background:background_settings_getter",
])