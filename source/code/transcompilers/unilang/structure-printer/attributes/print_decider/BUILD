package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "attribute_section_newline_getter", deps = [
"//code/transcompilers/unilang/options/sections/method/attributes/specific/method:method_attribute_settings",
"//code/transcompilers/unilang/options/sections/method/attributes/specific/argument:argument_attribute_settings",
"//code/transcompilers/unilang/structure-printer:function_declaration_location",
])

hcp(name = "attribute_placement_tester", deps = [
"//code/transcompilers/unilang/options/sections/method/attributes/specific/parts/placements:all_method_attribute_placements",
"//code/transcompilers/unilang/options/sections/method/attributes/specific/parts/placements:all_argument_attribute_placements",
"//code/transcompilers/unilang/structure-printer:function_declaration_location",
])

hcp(name = "attribute_print_decider", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/method/arguments/argument:function_argument",
"//code/transcompilers/unilang/structure-printer:function_declaration_location",
"attribute_placement_tester",
"//code/transcompilers/unilang/options/sections/method/attributes:all_method_attribute_settings",
])