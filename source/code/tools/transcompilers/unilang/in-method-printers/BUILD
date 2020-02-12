package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "body_param_in_method_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/utilities/program/common_actions/exits:lib",
"//code/utilities/converters:lib",
])

hcp(name = "data_member_in_method_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/tools/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/utilities/program/common_actions/exits:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "foreign_method_call_in_method_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/utilities/program/common_actions/exits:lib",
"//code/utilities/converters:lib",
])

hcp(name = "method_call_in_method_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/utilities/program/common_actions/exits:lib",
"//code/utilities/converters:lib",
"//code/utilities/colors:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])