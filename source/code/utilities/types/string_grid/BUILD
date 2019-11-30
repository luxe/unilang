package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "random_letter_filler", deps = [
    "//code/utilities/std_hackery:std_aliases",
    "//code/utilities/types/char:optional_letter_case",
    "//code/utilities/random:lib",
])