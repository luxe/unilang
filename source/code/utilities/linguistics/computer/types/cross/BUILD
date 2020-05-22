package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "cross_language_type",
    deps = [
        "//code/tools/transcompilers/unilang/options/self_describe_type:inferred_type_properties",
        "//code/utilities/linguistics/computer/types/cross/language_type",
        "//code/utilities/types:tri_bool",
    ],
)
