package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "attribute_technique")

hcp(
    name = "attribute_style",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts:attribute_technique",
    ],
)

hcp(name = "attribute_usage_note")
