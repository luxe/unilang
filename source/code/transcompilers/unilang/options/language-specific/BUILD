package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

cpp_object("c_language_version")

hcp("c_export_settings",deps = [
"//code/transcompilers/unilang/options/sections:portion_options",
"//code/transcompilers/unilang/options:general_options",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/options:test_wrapper_options",
])

hcp("hidl_export_settings",deps = [
"//code/transcompilers/unilang/options/sections:portion_options",
"//code/transcompilers/unilang/options:general_options",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/options:build_rule_settings",
])

hcp("cpp_export_settings",deps = [
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings"
])

hcp("csharp_export_settings",deps = [
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings"
])

hcp("d_export_settings",deps = [
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings"
])

hcp("rust_export_settings",deps = [
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings"
])

hcp("plant_uml_settings",deps = [
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings"
])
