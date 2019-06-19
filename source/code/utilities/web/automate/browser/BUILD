package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "browser_creator", deps = [
    "@pybind11//:pybind11",
    "//code/utilities/web/automate/browser:browser_settings",
])

hcp(name = "browser_settings", deps = [
])