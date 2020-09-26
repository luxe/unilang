package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "json_attribute_check_settings",
    deps = [
    ],
)

hcp(
    name = "json_attribute_checker",
    deps = [
        "//code/utilities/formats/json/attribute_check:json_attribute_check_settings",
    ],
)
