package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "chrome_version_getter",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/system:lib",
        "//code/utilities/types/strings/observers/columns:lib",
    ],
)

cpp_main(
    name = "chrome_version",
    deps = [
        "//code/utilities/web/chrome/version:chrome_version_getter",
    ],
)
