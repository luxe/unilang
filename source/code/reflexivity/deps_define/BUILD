package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(name = "deps_definition_refresher", deps = [
    "//code/utilities/filesystem/paths:lib",
    "//code/reflexivity/tool_chain_conversion/conversion_test_data:bazel_conversion_tests",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/filesystem/files/deleting:lib",
    "//code/utilities/types/vectors/converters:lib",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/reflexivity/tool_chain_conversion/conversion_test_data:test_getter",
    "//code/reflexivity/tool_chain_conversion:readme_creator",
    "//code/transcompilers/unilang/file_extension_getter:file_extension_getter",
])