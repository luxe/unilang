package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")


hcp(name="text_to_bitmap", deps = [
"//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:full_color_bitmap",
"//code/utilities/graphics/imgui/render/elements:full_color_bitmap_drawer",
"//code/utilities/types/char:lib",
"//code/utilities/fonts/bdf/settings:character_segment",
"//code/utilities/data_structures/graphics/text:str_to_bdf_segments",
"//code/utilities/fonts/bdf/character_maps:character_maps",
"//code/utilities/graphics/imgui:imgui_type_utility",
"//code/utilities/colors:color_defaults",
])

hcp(name="str_to_bdf_segments", deps = [
"//code/utilities/data_structures/graphics/bitmap/full_color_bitmap:full_color_bitmap",
"//code/utilities/graphics/imgui/render/elements:full_color_bitmap_drawer",
"//code/utilities/types/char:lib",
"//code/utilities/fonts/bdf/settings:character_segment",
])