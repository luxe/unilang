package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "processing_options", deps = [
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/tools/transcompilers/unilang/options/sections:portion_options",
"//code/tools/transcompilers/unilang/options:general_options",
])
