package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "frame_renderer",
    interface_deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:positioned_full_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/image:positioned_texture",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/graphics/cairo/render:cairo_render_settings",
        "//code/utilities/graphics/cairo/render:cairo_surface_creator",
        "//code/utilities/graphics/imgui/render/elements:line_drawer",
        "//code/utilities/graphics/imgui/render/elements:multi_color_bitmap_drawer",
        "//code/utilities/graphics/imgui/render/elements:rectangle_drawer",
        "//code/utilities/math",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/variant:lib",
        "//code/utilities/deps/external/cairo:lib",
        "//code/utilities/deps/external/imgui:lib",
    ],
)

hcp_hdrs_derive(
    name = "cairo_surface_creator",
    interface_deps = [
        "//code/utilities/data_structures/color:transparent_rgb_color",
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:positioned_full_color_bitmap",
        "//code/utilities/data_structures/graphics/bitmap/multi_color_bitmap:positioned_multi_color_bitmap",
        "//code/utilities/data_structures/graphics/image:positioned_texture",
        "//code/utilities/data_structures/graphics/objects:frame_elements",
        "//code/utilities/graphics/cairo/render:cairo_render_settings",
        "//code/utilities/graphics/imgui/render/elements:line_drawer",
        "//code/utilities/graphics/imgui/render/elements:multi_color_bitmap_drawer",
        "//code/utilities/graphics/imgui/render/elements:rectangle_drawer",
        "//code/utilities/math",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/variant:lib",
        "//code/utilities/deps/external/cairo:lib",
    ],
)

hcp_hdrs_derive(
    name = "cairo_render_settings",
    interface_deps = [
        "//code/utilities/data_structures/color:rgb_color",
        "//code/utilities/graphics/cairo/render:cairo_surface_settings",
    ],
)

hcp_hdrs_derive(
    name = "cairo_surface_settings",
    interface_deps = [
        "//code/utilities/data_structures/position",
    ],
)
