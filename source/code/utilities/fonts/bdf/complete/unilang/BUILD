package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "unilang_segments", deps = [
"//code/tools/transcompilers/unilang/tokens:generic_token",
"//code/tools/transcompilers/unilang/tokens:get_tokens",
"//code/utilities/fonts/bdf/settings:bdf_settings",
"//code/utilities/fonts/bdf/glyph:glyphs",
"//code/tools/transcompilers/unilang/tokens/uniqueness:unique_tokens_checker",
"//code/utilities/fonts/bdf/exporter:bdf_settings_to_format",
])

hcp(name = "unilang_font_creation_settings", deps = [
    "//code/utilities/fonts/bdf/complete/unilang:unilang_segments",
    "//code/utilities/fonts/bdf/complete:font_creation_settings",
    "//code/utilities/filesystem/paths:lib",
])

hcp(name = "unilang_character_maps", deps = [
    "//code/utilities/fonts/bdf/settings:character_segment",
    "//code/utilities/graphics/sdl:sdl_init_settings",
    "//code/tools/transcompilers/unilang/tokens:get_tokens",
    "//code/utilities/fonts/bdf/character_maps:character_maps",
    "//code/utilities/fonts/bdf/complete/unilang:unilang_segments",
    "//code/utilities/fonts/bdf/character_maps:character_maps_getter",
])

