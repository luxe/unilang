package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "random_letter_filler", deps = [
    "//code/utilities/language_basic/std_hackery:std_aliases",
    "//code/utilities/types/char:optional_letter_case",
    "//code/utilities/random:lib",
])

hcp(name = "words_finder", deps = [
    "//code/utilities/language_basic/std_hackery:std_aliases",
    "//code/utilities/data_structures/counters/unique_counter:unique_counter",
    "//code/utilities/types/strings/observers/comparing:lib",
])