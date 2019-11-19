package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")


#build main and deploy stuff
cc_binary(
    name = "crossword",
    srcs = ["crossword.cpp"],
    deps = [
        "//code/tools/crossword:crossword_maker"
    ]
)

hcp(name = "crossword_maker", deps = [
    "//code/utilities/types/vectors/creators:lib",
    "//code/utilities/printers:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/random:lib",
    "//code/utilities/data_structures:compass_direction",
    "//code/utilities/data_structures/point:point",
    "//code/utilities/data_structures:compass_direction_diagnonal",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/tools/crossword/settings:crossword_puzzle_settings",
    "//code/tools/crossword:word_try",
    "//code/tools/crossword:html_exporter",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/tools/crossword:crossword_words",
    "//code/utilities/data_structures/point:point_mover",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/utilities/std_hackery:std_aliases",
    "//code/tools/crossword/settings:crossword_puzzle_settings_getter",
    "//code/tools/crossword:random_word_placer",
    "//code/utilities/types/strings/transformers/casing:letter_case_setter",
])

hcp(name = "random_word_placer", deps = [
    "//code/utilities/data_structures/point:point_mover",
    "//code/tools/crossword/settings:crossword_puzzle_settings",
    "//code/tools/crossword:word_try",
    "//code/utilities/std_hackery:std_aliases",
    "//code/tools/crossword/settings:crossword_puzzle_settings_getter",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/utilities/types/vectors/creators:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/printers:lib",
    "//code/utilities/random:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/tools/crossword:html_exporter",
])

hcp(name = "crossword_words", deps = [
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/std_hackery:std_aliases",
])

hcp(name = "word_try", deps = [
    "//code/utilities/data_structures:compass_direction_diagnonal",
    "//code/utilities/data_structures/point:point",
])

hcp(name = "html_exporter", deps = [
    "//code/tools/crossword/settings:crossword_puzzle_settings",
    "//code/utilities/types/vectors/creators:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/colors:color_palettes",
    "//code/utilities/random:lib",
])