package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "terminal_background_changer",
    deps = [
        "//code/utilities/math",
        "//code/utilities/peripheral/screen/good_bad:rgb_section",
        "//code/utilities/program/call:lib",
    ],
)
