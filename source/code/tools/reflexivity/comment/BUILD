package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "generated_comment_getter", deps = [
    "//code/utilities/program/name:program_name_getter",
    "//code/utilities/types/strings/transformers/appending:lib",
])