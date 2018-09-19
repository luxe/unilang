package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "struct_manipulation_settings", deps = [
"//code/transcompilers/unilang/options/manipulation/meta:meta_manipulation_settings",
"//code/transcompilers/unilang/options/manipulation/imports:import_manipulation_settings",
"//code/transcompilers/unilang/options/manipulation/enums:enum_manipulation_settings",
"//code/transcompilers/unilang/options/manipulation/methods:method_manipulation_settings",
"//code/transcompilers/unilang/options/manipulation:case_adjustment_settings",
"//code/transcompilers/unilang/options/manipulation/types:type_manipulation_settings",
"//code/transcompilers/unilang/options/manipulation/data_members:data_member_manipulation_settings",
])

hcp(name = "token_case_settings", deps = [
"//code/utilities/types/strings/transformers/casing:case_format_style",
])

hcp(name = "case_adjustment_settings", deps = [
"token_case_settings"
])

hcp(name = "comment_adjustment_settings", deps = [
"//code/transcompilers/unilang/options/comment:comment_grammar_settings",
"//code/transcompilers/unilang/options/manipulation/reflow:comment_reflow_settings",
])