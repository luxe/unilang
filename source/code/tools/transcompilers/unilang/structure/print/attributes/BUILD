package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "method_attributes_getter", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_argument",
"//code/tools/transcompilers/unilang/structure/print:function_declaration_location",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/tools/transcompilers/unilang/structure/print/attributes/print_decider:attribute_print_decider",
"//code/tools/transcompilers/unilang/structure/print/attributes/string_creator:attribute_style_to_string_converter",
"//code/tools/transcompilers/unilang/structure/print/attributes/print_decider:attribute_section_newline_getter",
])