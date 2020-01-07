package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "bazel_config_settings", deps = [
])

hcp(name = "bazel_config_deriver", deps = [
    "//code/utilities/filesystem/files/getting:lib",
    "//code/utilities/bazel/config:bazel_config_settings",
])