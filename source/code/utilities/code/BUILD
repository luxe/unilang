package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="concept_tree_getter",deps = [
    "//code/utilities/data_structures/tree/generic:string_tree",
    "@tree//:tree",
])

hcp(name="concept_tree_to_image",deps = [
    "//code/utilities/data_structures/tree/generic:string_tree",
    "//code/utilities/code:concept_tree_getter",
])