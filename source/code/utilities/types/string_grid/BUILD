package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "random_letter_filler", deps = [
    "//code/utilities/std_hackery:std_aliases",
    "//code/utilities/types/char:optional_letter_case",
    "//code/utilities/random:lib",
])

hcp(name = "words_finder", deps = [
    "//code/utilities/std_hackery:std_aliases",
    "//code/utilities/data_structures/unique_counter:unique_counter",
    "//code/utilities/types/strings/observers/comparing:lib",
])