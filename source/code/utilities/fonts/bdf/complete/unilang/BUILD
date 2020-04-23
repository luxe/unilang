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