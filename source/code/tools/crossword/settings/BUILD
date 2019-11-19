package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")



hcp(name = "crossword_puzzle_settings", deps = [
    "//code/utilities/data_structures/dimensions:two_d_dimensions",
    "//code/tools/crossword/settings:crossword_random_place_settings",
    "//code/utilities/colors:color_palettes",
    "//code/utilities/types/char:optional_letter_case",
])


hcp(name = "crossword_puzzle_settings_getter", deps = [
    "//code/tools/crossword/settings:crossword_puzzle_settings",
    "//code/tools/crossword:crossword_words",
    "//code/utilities/colors:color_palettes",
])

hcp(name = "crossword_random_place_settings", deps = [
])