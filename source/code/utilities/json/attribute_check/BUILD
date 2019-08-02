package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "json_attribute_check_settings", deps = [
])

hcp(name = "json_attribute_checker", deps = [
    "//code/utilities/json/attribute_check:json_attribute_check_settings",
])