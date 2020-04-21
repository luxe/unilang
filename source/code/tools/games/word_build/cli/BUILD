package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")


#build main and deploy stuff
cc_binary(
    name = "word_builder",
    srcs = ["word_builder.cpp"],
    deps = [
        "//code/tools/games/word_build/cli:word_builder_game_maker"
    ],
    data = ["@scrabble_words//:all"],
)

hcp(name = "word_builder_game_maker", deps = [
    "//code/utilities/streams/filestreams/read_all:lib",
    "//code/utilities/types/char:lib",
    "//code/utilities/random:lib",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/linguistics/build_word/game:build_word_puzzle",
    "//code/utilities/linguistics/build_word/game/settings:build_word_game_settings_getter",
    "//code/tools/games/word_build/cli:html_exporter",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/linguistics/build_word/game:puzzle_builder",
])

hcp(name = "html_exporter", deps = [
    "//code/utilities/colors:color_palettes",
    "//code/utilities/language_basic/std_hackery:std_aliases",
    "//code/utilities/linguistics/build_word/game:build_word_puzzle",
    "//code/utilities/linguistics/build_word/game/settings:build_word_game_settings",
    "//code/utilities/types/vectors/creators:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/random:lib",
    "//code/utilities/formats/html:basic_html_template_getter",
    "//code/utilities/program/call:lib",
    "//code/utilities/peripheral/printer:pdf_printer",
])
