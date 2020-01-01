package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(name = "tool_chain_conversion_refresher", deps = [
"//code/utilities/filesystem/paths:lib",
"//code/tools/reflexivity/tool_chain_conversion/conversion_test_data:bazel_conversion_tests",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/filesystem/files/creating:lib",
"//code/utilities/filesystem/files/deleting:lib",
"//code/utilities/types/vectors/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/tools/reflexivity/tool_chain_conversion/conversion_test_data:test_getter",
"//code/tools/reflexivity/tool_chain_conversion:readme_creator",
"//code/tools/transcompilers/unilang/file_extension_getter:file_extension_getter",
])

hcp(name = "readme_creator", deps = [
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/filesystem/files/creating:lib",
])