package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(name = "build_word_game_settings", deps = [])

hcp(name = "build_word_game_settings_getter", deps = [
    "//code/utilities/linguistics/build_word/game/settings:build_word_game_settings",
    "//code/utilities/streams/filestreams/read_all:lib",
    "//code/utilities/types/char:lib",
    "//code/utilities/random:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/types/strings/observers/other:lib",
])