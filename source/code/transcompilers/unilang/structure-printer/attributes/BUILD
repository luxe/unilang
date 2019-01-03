package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "method_attributes_getter", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/method/arguments/argument:function_argument",
"//code/transcompilers/unilang/structure-printer:function_declaration_location",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/sections/meta:code_type",
"//code/transcompilers/unilang/structure-printer/attributes/print_decider:attribute_print_decider",
"//code/transcompilers/unilang/structure-printer/attributes/string_creator:attribute_style_to_string_converter",
"//code/transcompilers/unilang/structure-printer/attributes/print_decider:attribute_section_newline_getter",
])