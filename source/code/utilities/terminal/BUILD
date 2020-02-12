package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "terminal_background_changer",deps=[
    "//code/utilities/math:math",
    "//code/utilities/program/call:lib",
    "//code/utilities/peripheral/screen/good_bad:rgb_section",
])