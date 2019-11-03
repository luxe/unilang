package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "bazel_wrapper_refresher", deps = [
    "//code/reflexivity/bazel_wrapper/data:bazel_wrapper_refresh_settings_getter",
    "//code/utilities/types/strings/transformers/appending:lib"
])