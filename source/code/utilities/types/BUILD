package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "tri_bool",
    values = [
        "yes",
        "no",
        "unknown",
    ],
)

hcp_hdrs_derive(
    name = "tri_string",
    interface_deps = [
        "//code/utilities/deps/stl/string:lib",
    ],
)
