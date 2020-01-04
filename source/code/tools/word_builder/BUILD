package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
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
        "//code/tools/word_builder:word_builder_game_maker"
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
])