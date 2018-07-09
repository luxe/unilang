package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

cpp_object(name = "code_partition_method")
cpp_object(name = "constraint_export_style")

hcp(name = "test_wrapper_options")

hcp(name = "general_options", deps = [
"//code/transcompilers/unilang/options/comment:comment_settings",
"//code/transcompilers/unilang/options:code_partition_method",
"//code/transcompilers/unilang/options/design_strategy:object_export_method",
"//code/transcompilers/unilang/options/design_strategy:in_out_export_api_style",
"//code/transcompilers/unilang/options/filesystem:general_filesystem_naming",
"//code/transcompilers/unilang/options:constraint_export_style",
"//code/transcompilers/unilang/options/language-specific:c_language_version",
])

hcp(name = "foreign_language_export_settings", deps = [
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/options/language-specific:cpp_export_settings",
"//code/transcompilers/unilang/options/language-specific:d_export_settings",
"//code/transcompilers/unilang/options/language-specific:rust_export_settings",
"//code/transcompilers/unilang/options/language-specific:csharp_export_settings",
"//code/transcompilers/unilang/options/language-agnostic:language_agnostic_export_settings",
"//code/transcompilers/unilang/options/language-specific:hidl_export_settings",
"//code/transcompilers/unilang/options/language-specific/plant_uml_settings:plant_uml_settings",
"//code/transcompilers/unilang/options/language-specific/protocol_buffer_settings:protocol_buffer_settings",
"//code/transcompilers/unilang/options/language-specific:call_graph_options",
"//code/transcompilers/unilang/options/language-specific:html_table_options",
"//code/transcompilers/unilang/options/language-specific:treesheets_options",
"//code/transcompilers/unilang/options/bazel:build_rule_settings",
])

hcp(name = "export_settings", deps = [
"foreign_language_export_settings",
"//code/transcompilers/unilang/options/unilang:unilang_export_settings",
])

hcp(name = "remote_build_settings")