package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/unilang:generate_unilang_token_files.bzl", "generate_unilang_token_files")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "token_bdf_settings",
    deps = ["//code/utilities/fonts/bdf/settings:bdf_settings"],
)

hcp(
    name = "token_bdf_settings_getter",
    deps = [
        "//code/utilities/fonts/bdf/characters:predefined_characters",
        "//code/utilities/fonts/bdf/glyph:glyphs",
        "//code/utilities/fonts/bdf/tokens:token_bdf_settings",
    ],
)
