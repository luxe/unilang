package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "enum_explicit_value_strategy")

hcp(
    name = "enum_manipulation_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/manipulation:comment_adjustment_settings",
        "//code/tools/transcompilers/unilang/options/manipulation/enums:enum_explicit_value_strategy",
    ],
)
