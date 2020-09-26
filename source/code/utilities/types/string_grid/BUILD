package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "random_letter_filler",
    deps = [
        "//code/utilities/language_basic/std_hackery:std_aliases",
        "//code/utilities/random:lib",
        "//code/utilities/types/char:optional_letter_case",
    ],
)

hcp(
    name = "words_finder",
    deps = [
        "//code/utilities/data_structures/counters/unique_counter",
        "//code/utilities/language_basic/std_hackery:std_aliases",
        "//code/utilities/types/strings/observers/comparing:lib",
    ],
)
