package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "token_import_type_relation_attribute_settings")

hcp(
    name = "token_import_attribute_settings",
    deps = ["token_import_type_relation_attribute_settings"],
)
