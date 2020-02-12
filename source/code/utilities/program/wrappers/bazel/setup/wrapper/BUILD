package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")


hcp(name = "bazel_wrapper", deps = [
])

hcp(name = "bazel_wrapper_deriver", deps = [
    "//code/utilities/filesystem/files/getting:lib",
    "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper",
])