package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "browser_navigator", deps = [
    "@pybind11//:pybind11",
    "//code/utilities/web/automate/browser:browser_settings",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/types/strings/transformers/squeeze:lib",
    "//code/utilities/types/strings/transformers/trimming:lib",
    "//code/utilities/time/sleeping:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/web:lib",
    "//code/utilities/exits:lib",
    "//code/utilities/printers:lib",
    "//code/utilities/json/functions:lib",
])