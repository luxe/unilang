package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp("markdown_settings",deps = [
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/tools/transcompilers/unilang/options/language-specific/markdown:header_settings",
"//code/tools/transcompilers/unilang/options/language-specific/markdown:outline_settings",
"//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_image_settings",
"//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_table_settings",
"//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_code_settings",
"//code/tools/transcompilers/unilang/options/language-specific/markdown:sentence_settings",
"//code/tools/transcompilers/unilang/options/sections:portion_options",
"//code/tools/transcompilers/unilang/options:general_options",
"//code/tools/transcompilers/unilang/options/comment:comment_grammar_settings"
])

hcp("header_settings",deps = [
])

hcp("outline_settings",deps = [
])

hcp("markdown_image_settings",deps = [
])

hcp("markdown_code_settings",deps = [
])

hcp("markdown_table_settings",deps = [
])

hcp("sentence_settings",deps = [
])