package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/rules/data:package_binaries.bzl", "package_binaries")

distributable_cpp_main(
    name = "crash_on_sleep",
    depends = [
    ],
    description = "Crash tools that sleep",
    deps = [
        "//code/utilities/program/common_actions/exits:lib",
    ],
)
