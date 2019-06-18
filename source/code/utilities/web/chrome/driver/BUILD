package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(name = "chrome_driver_selector", deps = [
    "//code/utilities/shell:lib",
    "//code/utilities/types/strings/observers/columns:lib",
    "//code/utilities/web/chrome/version:chrome_version_getter",
])