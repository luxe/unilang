package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "code_partition_method")
cpp_object(name = "constraint_export_style")

hcp(name = "test_wrapper_options")

hcp(name = "general_options", deps = [
"//code/tools/transcompilers/unilang/options/comment:comment_settings",
"//code/tools/transcompilers/unilang/options:code_partition_method",
"//code/tools/transcompilers/unilang/options/design_strategy:object_export_method",
"//code/tools/transcompilers/unilang/options/design_strategy:in_out_export_api_style",
"//code/tools/transcompilers/unilang/options/filesystem:general_filesystem_naming",
"//code/tools/transcompilers/unilang/options:constraint_export_style",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_language_version",
])

hcp(name = "foreign_language_export_settings", deps = [
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/options/language-specific/cpp:cpp_export_settings",
"//code/tools/transcompilers/unilang/options/language-specific/cpp:cpp_test_export_settings",
"//code/tools/transcompilers/unilang/options/language-specific/cpp:cpp_benchmark_export_settings",
"//code/tools/transcompilers/unilang/options/language-specific/cpp:cpp_fuzz_export_settings",
"//code/tools/transcompilers/unilang/options/language-specific/d:d_export_settings",
"//code/tools/transcompilers/unilang/options/language-specific/rust:rust_export_settings",
"//code/tools/transcompilers/unilang/options/language-specific/csharp:csharp_export_settings",
"//code/tools/transcompilers/unilang/options/language-agnostic:language_agnostic_export_settings",
"//code/tools/transcompilers/unilang/options/language-specific/hidl:hidl_export_settings",
"//code/tools/transcompilers/unilang/options/language-specific/plant_uml_settings:plant_uml_settings",
"//code/tools/transcompilers/unilang/options/language-specific/protocol_buffer_settings:protocol_buffer_export_settings",
"//code/tools/transcompilers/unilang/options/language-specific/call_graph:call_graph_options",
"//code/tools/transcompilers/unilang/options/language-specific/html_table:html_table_options",
"//code/tools/transcompilers/unilang/options/language-specific/treesheets:treesheets_options",
"//code/tools/transcompilers/unilang/options/language-specific/mermaid:mermaid_settings",
"//code/tools/transcompilers/unilang/options/language-specific/dzslides:dzslides_settings",
"//code/tools/transcompilers/unilang/options/language-specific/slidy:slidy_settings",
"//code/tools/transcompilers/unilang/options/language-specific/processing:processing_options",
"//code/tools/transcompilers/unilang/options/language-specific/markdown:markdown_settings",
"//code/tools/transcompilers/unilang/options/language-specific/java:java_settings",
"//code/tools/transcompilers/unilang/options/language-specific/java:java_test_settings",
"//code/tools/transcompilers/unilang/options/bazel:build_rule_settings",
])

hcp(name = "export_settings", deps = [
"foreign_language_export_settings",
"//code/tools/transcompilers/unilang/options/unilang:unilang_export_settings",
])

hcp(name = "remote_build_settings")
hcp(name = "remote_program_settings")
hcp(name = "workspace_settings")
