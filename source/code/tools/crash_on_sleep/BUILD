package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")

distributable_cpp_main(
    name = "crash_on_sleep",
    deps = [
        "//code/utilities/exits:lib"
    ],
    description = "Crash tools that sleep",
    depends = [
    ],
)