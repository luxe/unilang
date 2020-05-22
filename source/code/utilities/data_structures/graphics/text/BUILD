package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "text_to_bitmap",
    deps = [
        "//code/utilities/colors:color_defaults",
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap",
        "//code/utilities/data_structures/graphics/text:str_to_bdf_segments",
        "//code/utilities/fonts/bdf/character_maps",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/graphics/imgui:imgui_type_utility",
        "//code/utilities/graphics/imgui/render/elements:full_color_bitmap_drawer",
        "//code/utilities/types/char:lib",
    ],
)

hcp(
    name = "str_to_bdf_segments",
    deps = [
        "//code/utilities/data_structures/graphics/bitmap/full_color_bitmap",
        "//code/utilities/fonts/bdf/settings:character_segment",
        "//code/utilities/graphics/imgui/render/elements:full_color_bitmap_drawer",
        "//code/utilities/types/char:lib",
    ],
)
