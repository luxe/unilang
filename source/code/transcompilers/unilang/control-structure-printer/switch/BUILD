package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "switch_case_statement")

hcp(name = "switch_block", deps = [
"//code/transcompilers/unilang/control-structure-printer/switch:switch_case_statement"
])

hcp(name = "switch_block_printer", deps = [
"//code/transcompilers/unilang/control-structure-printer/switch:switch_block",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/converters:lib",
])