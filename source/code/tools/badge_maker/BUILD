package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "badge_maker", deps = [
    "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:full_color_bitmap",
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/tools/ide/settings:ide_settings",
    "//code/utilities/data_structures/graphics/objects/label:label_settings",
    "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
    "//code/utilities/graphics/imgui/render/elements:rectangle_drawer",
    "//code/utilities/graphics/imgui/render/elements:full_color_bitmap_drawer",
    "//code/utilities/data_structures/graphics/text:text_to_bitmap",
    "//code/utilities/graphics/imgui:ui_renders",
    "//code/tools/transcompilers/unilang/tokens:get_tokens",
    "//code/utilities/data_structures/graphics/bitmap/pixel:pixel_slider",
    "//code/utilities/colors:rectangle_shades",
    "//code/utilities/data_structures/graphics/objects/faced_label:positioned_faced_label",
    "//code/utilities/data_structures/graphics/objects/style:default_label_styles",
    "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_converter",
    "//code/utilities/data_structures/graphics/objects/mouse/premade:standard_mouse",
    "//code/utilities/fonts/bdf/complete/unilang:unilang_segments",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/fonts/bdf/character_maps:character_maps_getter",
    "//code/utilities/graphics/imgui/background:background_settings_getter",
    "//code/utilities/execution:thread_pool_getter",
    "//code/utilities/data_structures/graphics/objects/slider:default_sliders",
    "//code/utilities/graphics/cairo/render:frame_renderer",
    "//code/utilities/data_structures/graphics/objects:frame_elements",
    "//code/utilities/data_structures/graphics/objects/faced_label:faced_label_drawer",
    "//code/utilities/graphics/cairo/render:cairo_render_settings",
])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/tools/badge_maker:badge_maker"]
)
