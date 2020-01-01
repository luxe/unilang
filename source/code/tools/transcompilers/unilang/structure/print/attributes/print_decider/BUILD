package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "attribute_section_newline_getter", deps = [
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/method:method_attribute_settings",
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/argument:argument_attribute_settings",
"//code/tools/transcompilers/unilang/structure/print:function_declaration_location",
])

hcp(name = "attribute_placement_tester", deps = [
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts/placements:all_method_attribute_placements",
"//code/tools/transcompilers/unilang/options/sections/method/attributes/specific/parts/placements:all_argument_attribute_placements",
"//code/tools/transcompilers/unilang/structure/print:function_declaration_location",
])

hcp(name = "attribute_print_decider", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_argument",
"//code/tools/transcompilers/unilang/structure/print:function_declaration_location",
"attribute_placement_tester",
"//code/tools/transcompilers/unilang/options/sections/method/attributes:all_method_attribute_settings",
])