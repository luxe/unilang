package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")


hcp(
    name = "virtual_method_checker",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/code/symbols:token_attribute_settings",
],
)