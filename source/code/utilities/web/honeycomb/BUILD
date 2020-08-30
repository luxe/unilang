package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "honeycomb_poster",
    deps = [
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
    ],
)