package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

cpp_object(name = "enum_explicit_value_strategy")
hcp(name = "enum_manipulation_settings", deps = [
"//code/transcompilers/unilang/options/manipulation/enums:enum_explicit_value_strategy",
"//code/transcompilers/unilang/options/manipulation:comment_adjustment_settings",
])