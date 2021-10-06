package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "label_style",
    interface_deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/graphics/objects/cursor/data:label_cursor",
        "//code/utilities/data_structures/graphics/objects/label/style:label_width_style",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_settings",
        "//code/utilities/data_structures/shapes/rectangle:rectangle_shade_colors",
    ],
)

hcp_hdrs_derive(
    name = "label_styles",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/label/style:label_style",
    ],
)

hcp_hdrs_derive(
    name = "label_width_style",
    interface_deps = [
        "//code/utilities/data_structures/graphics/bitmap/pixel:pixel_slider",
    ],
)

hcp_hdrs_derive(
    name = "label_style_chooser",
    interface_deps = [
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
    ],
)

hcp_hdrs_derive(
    name = "default_label_styles",
    interface_deps = [
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/colors/defaults:color_defaults",
        "//code/utilities/colors/defaults:rectangle_shades",
        "//code/utilities/colors/transformers:color_shader",
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/pixel:pixel_slider",
        "//code/utilities/data_structures/graphics/objects/cursor/premade:blue_cursor",
        "//code/utilities/data_structures/graphics/objects/cursor/premade:color_cursor",
        "//code/utilities/data_structures/graphics/objects/cursor/premade:red_cursor",
        "//code/utilities/data_structures/graphics/objects/label/data:label_settings",
        "//code/utilities/data_structures/graphics/objects/mouse/events:mouse_events_checker",
        "//code/utilities/data_structures/graphics/text:text_to_bitmap",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/graphics/imgui:ui_renders",
        "//code/utilities/graphics/imgui/render/elements:full_color_bitmap_drawer",
        "//code/utilities/graphics/imgui/render/elements:rectangle_drawer",
    ],
)
