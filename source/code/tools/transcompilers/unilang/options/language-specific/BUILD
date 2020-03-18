package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp("hidl_export_settings",deps = [
"//code/tools/transcompilers/unilang/options/sections:portion_options",
"//code/tools/transcompilers/unilang/options:general_options",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/tools/transcompilers/unilang/options/bazel:build_rule_settings",
])

hcp("d_export_settings",deps = [
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings"
])

hcp("rust_export_settings",deps = [
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings"
])

hcp("mermaid_settings",deps = [
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/tools/transcompilers/unilang/options/language-specific/mermaid:mermaid_graph_orientation",
"//code/tools/transcompilers/unilang/design/normal:method_sorter",
"//code/tools/transcompilers/unilang/options/sections:portion_options",
"//code/tools/transcompilers/unilang/options:general_options",
])

hcp(name = "html_table_options", deps = [
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
])

hcp(name = "treesheets_options", deps = [
"//code/utilities/types/strings/transformers/casing:case_format_style"
])

hcp(name = "processing_options", deps = [
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/tools/transcompilers/unilang/options/sections:portion_options",
"//code/tools/transcompilers/unilang/options:general_options",
])
