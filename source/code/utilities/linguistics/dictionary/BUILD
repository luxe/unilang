package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")
load("//bazel/rules/data:distributable_data.bzl", "distributable_data")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp_hdrs_derive(
    name = "scrabble_2019",
    data = ["@scrabble_words//:all"],
    interface_deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
    ],
)

hcp_hdrs_derive(
    name = "dictionary_getter",
    interface_deps = [
        "//code/utilities/deps/external/nuspell:lib",
    ],
)

hcp_hdrs_derive(
    name = "dictionary_spellcheck_results",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "dictionary_spellcheck",
    interface_deps = [
        "//code/utilities/linguistics/dictionary:dictionary_spellcheck_results",
        "//code/utilities/deps/external/nuspell:lib",
    ],
)

hcp_hdrs_derive(
    name = "three_letter_words",
    data = ["@scrabble_words//:all"],
    interface_deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
    ],
)

hcp_hdrs_derive(
    name = "wordle",
    data = ["@scrabble_words//:all"],
    interface_deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
    ],
)
