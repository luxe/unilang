package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "font_creation_settings",
    deps = [
        "//code/utilities/fonts/bdf/settings:character_segment",
    ],
)

hcp(
    name = "font_creator",
    deps = [
        "//code/tools/transcompilers/unilang/language-and-theme-creator/sublime:global",
        "//code/tools/transcompilers/unilang/tokens:generic_token",
        "//code/tools/transcompilers/unilang/tokens:get_tokens",
        "//code/tools/transcompilers/unilang/tokens/uniqueness:unique_tokens_checker",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/fonts/bdf/complete:font_creation_settings",
        "//code/utilities/fonts/bdf/complete/unilang:unilang_segments",
        "//code/utilities/fonts/bdf/exporter:bdf_settings_to_format",
        "//code/utilities/fonts/bdf/glyph:glyphs",
        "//code/utilities/fonts/bdf/settings:bdf_settings",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
