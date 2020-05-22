package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "token_import_type_relation_attribute_settings")

hcp(
    name = "token_import_attribute_settings",
    deps = ["token_import_type_relation_attribute_settings"],
)
