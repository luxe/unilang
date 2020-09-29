package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "network_ip_getter",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/converting:lib",
    ],
)


