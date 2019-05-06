package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp("slidy_settings",deps = [
    "//code/transcompilers/unilang/options/sections:portion_options",
    "//code/transcompilers/unilang/options:general_options",
    "//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
    "//code/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
    "//code/transcompilers/unilang/options/language-specific/slidy:slidy_creation_settings",
])

hcp("slidy_creation_settings",deps = [
])
