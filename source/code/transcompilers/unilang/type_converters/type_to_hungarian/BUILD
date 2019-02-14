package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "type_to_hungarian_notation_converter", deps=[
"//code/transcompilers/unilang/options/hungarian:identifier_notation_settings",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/prefix_creators:hungarian_left_prefix_decider",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/prefix_creators:hungarian_type_prefix_decider",
])

hcp(name = "data_member_to_hungarian_notation_converter", deps = [
"//code/transcompilers/unilang/type_converters/type_to_hungarian:type_to_hungarian_notation_converter",
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_argument",
"//code/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_result",
"//code/transcompilers/unilang/options/hungarian:identifier_notation_settings",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
"//code/transcompilers/unilang/structure/print/derivers:type_name_deriver",
"//code/utilities/converters:lib"
])