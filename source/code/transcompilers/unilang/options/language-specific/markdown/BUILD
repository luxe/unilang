package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp("markdown_settings",deps = [
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/options/language-specific/markdown:header_settings",
"//code/transcompilers/unilang/options/sections:portion_options",
"//code/transcompilers/unilang/options:general_options",
])

hcp("header_settings",deps = [
])