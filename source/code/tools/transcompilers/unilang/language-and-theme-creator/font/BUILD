package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "unilang_font_creator", deps = [
"//code/tools/transcompilers/unilang/tokens:generic_token",
"//code/tools/transcompilers/unilang/language-and-theme-creator/sublime:global",
"//code/tools/transcompilers/unilang/language-and-theme-creator/sublime:unilang_file_creator",
"//code/utilities/types/general:lib",
"//code/utilities/exits:lib",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/vectors/operators:lib",
"//code/tools/transcompilers/unilang/tokens:get_tokens",
"//code/tools/transcompilers/unilang/tokens/uniqueness:unique_tokens_checker",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/bdf/settings:bdf_settings",
"//code/utilities/bdf/exporter:bdf_settings_to_format",
"//code/utilities/bdf/glyph:glyphs",
"//code/tools/transcompilers/unilang/language-and-theme-creator/font:unilang_font",
"//code/tools/transcompilers/unilang/language-and-theme-creator/font:unilang_font_creation_settings_getter",
])

hcp(name = "predefined_characters", deps = [
"//code/utilities/bdf/settings:bdf_settings",
"//code/utilities/bdf/glyph:glyphs",
])

hcp(name = "unilang_font", deps = [
"//code/tools/transcompilers/unilang/tokens:generic_token",
"//code/tools/transcompilers/unilang/tokens:get_tokens",
"//code/utilities/bdf/settings:bdf_settings",
"//code/utilities/bdf/glyph:glyphs",
"//code/tools/transcompilers/unilang/tokens/uniqueness:unique_tokens_checker",
"//code/utilities/bdf/exporter:bdf_settings_to_format",
])

hcp(name = "unilang_font_creation_settings", deps = [
])

hcp(name = "unilang_font_creation_settings_getter", deps = [
    "//code/tools/transcompilers/unilang/language-and-theme-creator/font:unilang_font_creation_settings",
    "//code/utilities/filesystem/paths:lib",
])