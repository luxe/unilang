package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "switch_case_statement")

hcp(name = "switch_block", deps = [
"//code/tools/transcompilers/unilang/control-structure-printer/switch:switch_case_statement"
])

hcp(name = "switch_block_printer", deps = [
"//code/tools/transcompilers/unilang/control-structure-printer/switch:switch_block",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/utilities/types/converters:lib",
])