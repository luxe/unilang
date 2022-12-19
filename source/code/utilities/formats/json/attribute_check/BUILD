package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "json_attribute_check_settings",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "json_attribute_checker",
    interface_deps = [
        "//code/utilities/formats/json/attribute_check:json_attribute_check_settings",
    ],
)
