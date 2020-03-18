package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp("cpp_export_settings",deps = [
"//code/tools/transcompilers/unilang/options/sections:portion_options",
"//code/tools/transcompilers/unilang/options:general_options",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
])

hcp("cpp_test_export_settings",deps = [
"//code/tools/transcompilers/unilang/options/sections:portion_options",
"//code/tools/transcompilers/unilang/options:general_options",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
])

hcp("cpp_fuzz_export_settings",deps = [
"//code/tools/transcompilers/unilang/options/sections:portion_options",
"//code/tools/transcompilers/unilang/options:general_options",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
])

hcp("cpp_benchmark_export_settings",deps = [
"//code/tools/transcompilers/unilang/options/sections:portion_options",
"//code/tools/transcompilers/unilang/options:general_options",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
])