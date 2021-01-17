package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")




hcp(
    name = "argument_is_mutable",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/comments/doxygen/settings:doxygen_parameter_direction",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/code/symbols:token_attribute_settings",
        "//code/utilities/types/vectors/observers:lib",
],
)

hcp(
    name = "argument_is_reference",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/comments/doxygen/settings:doxygen_parameter_direction",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/code/symbols:token_attribute_settings",
        "//code/utilities/types/vectors/observers:lib",
],
)

hcp(
    name = "argument_is_pointer_like",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/code/query:argument_is_reference",
],
)

hcp(
    name = "argument_direction_decider",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/code/query:argument_is_mutable",
        "//code/utilities/code/query:argument_is_pointer_like",
],
)

hcp(
    name = "virtual_method_checker",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/code/symbols:token_attribute_settings",
],
)

hcp(
    name = "method_is_overloaded",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/strings/observers/other:lib",
],
)