package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "word_choice")

hcp(
    name = "word_choice_getter",
    deps = [
        "//code/utilities/linguistics/word_choice",
    ],
)
