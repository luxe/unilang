package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "tri_bool",
    values = [
        "yes",
        "no",
        "unknown",
    ],
)

hcp(name = "tri_string")
