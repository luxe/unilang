package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "word_speaker", deps = [
    "//code/utilities/random:lib",
    "//code/utilities/filesystem/files/temp:existing_temp_file",
    "//code/utilities/program/call:lib",
])  