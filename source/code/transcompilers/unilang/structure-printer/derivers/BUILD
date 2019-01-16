package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "structure_name_kind")

hcp(name = "struct_name_deriver", deps = [
"//code/utilities/types/strings/transformers/casing:case_modifier"
])

hcp(name = "type_name_deriver", deps = [
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_argument",
"//code/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_result",
"//code/transcompilers/unilang/structure/model/sections/typedef:typedef_argument",
"//code/transcompilers/unilang/structure/model/sections/typedef:typedef_result",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages/language_type:language_type",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter:unilang_type_to_language_type_converter",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:stripped_unilang_type_with_qualifiers",
"//code/utilities/converters:lib"
])

hcp(name = "structure_typename_deriver", deps = [
"//code/transcompilers/unilang/structure-printer/derivers:structure_name_kind",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "identifier_name_deriver", deps = [
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_argument",
"//code/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_result",
"//code/transcompilers/unilang/options/sections:notation_settings",
"//code/utilities/types:tri_bool",
"//code/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/transcompilers/unilang/units_to_variable_suffix_converter:units_to_variable_suffix_lookup_table",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/units_to_variable_suffix_converter:unit_suffix_lookuper",
"//code/transcompilers/unilang/options/self_describe_type:modify_identifier_with_extra_type_info",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter:unilang_type_to_language_type_converter",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/appending:lib",
])