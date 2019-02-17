package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp("markdown_settings",deps = [
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/options/language-specific/markdown:header_settings",
"//code/transcompilers/unilang/options/language-specific/markdown:outline_settings",
"//code/transcompilers/unilang/options/language-specific/markdown:markdown_image_settings",
"//code/transcompilers/unilang/options/sections:portion_options",
"//code/transcompilers/unilang/options:general_options",
"//code/transcompilers/unilang/options/comment:comment_grammar_settings"
])

hcp("header_settings",deps = [
])

hcp("outline_settings",deps = [
])

hcp("markdown_image_settings",deps = [
])