package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")


hcp(name = "user_action", deps = [
])

hcp(name = "user_action_getter", deps = [
    "//code/utilities/x11/events:global_event_listener",
    "//code/tools/mario/engine:user_action",
    "//code/utilities/x11/data:main_x11_state",
    "//code/utilities/types/booleans:lib",
])