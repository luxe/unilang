package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(name = "chrome_version_getter", deps = [
    "//code/utilities/program/call:lib",
    "//code/utilities/types/strings/observers/columns:lib",
    "//code/utilities/system:lib",
])

cpp_main(name = "chrome_version",deps = [
         "//code/utilities/web/chrome/version:chrome_version_getter"
])
