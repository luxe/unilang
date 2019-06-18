package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

hcp(name = "meta_settings", deps = [
])

hcp(name = "noogle_runner", deps = [
    "//code/tools/noogle:meta_settings",
])

distributable_cpp_main(
    name = "noogle",
    deps = [
        "//code/tools/noogle:noogle_runner",
        "//code/tools/noogle:meta_settings"
    ],
    data = ":debian-data",
    description = "google but numbers",
    depends = [],
)