package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "argument_attribute_line_breaking_settings")

hcp(name = "return_must_use_settings", deps = [
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts:attribute_usage_note",
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts:attribute_style",
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts/placements:all_method_attribute_placements",
])

hcp(name = "argument_non_null_settings", deps = [
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts:attribute_usage_note",
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts:attribute_style",
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts/placements:all_argument_attribute_placements",
])

hcp(name = "argument_unused_settings", deps = [
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts:attribute_usage_note",
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts:attribute_style",
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts/placements:all_argument_attribute_placements",
])

hcp(name = "argument_attribute_settings", deps = [
"argument_non_null_settings",
"argument_unused_settings",
"return_must_use_settings",
"argument_attribute_line_breaking_settings",
])