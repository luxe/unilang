package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name= "units_description_adder", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/transcompilers/unilang/doxygen_block_printer:value_constraint_comment_deriver",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/transcompilers/unilang/units_to_variable_suffix_converter:unit_suffix_lookuper",
"//code/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/utilities/converters:lib",
])

hcp(name = "return_results_description_adder", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/transcompilers/unilang/doxygen_block_printer/method_getter/adders:units_description_adder",
"//code/utilities/converters:lib",
])

hcp(name = "main_description_adder", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/transcompilers/unilang/doxygen_block_printer:value_constraint_comment_deriver",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/transcompilers/unilang/units_to_variable_suffix_converter:unit_suffix_lookuper",
"//code/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/utilities/converters:lib",
])

hcp(name = "contract_description_adder", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/transcompilers/unilang/doxygen_block_printer:value_constraint_comment_deriver",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/transcompilers/unilang/units_to_variable_suffix_converter:unit_suffix_lookuper",
"//code/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/utilities/converters:lib",
])

hcp(name = "argument_description_adder", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/transcompilers/unilang/doxygen_block_printer:value_constraint_comment_deriver",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/transcompilers/unilang/units_to_variable_suffix_converter:unit_suffix_lookuper",
"//code/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/transcompilers/unilang/doxygen_block_printer/method_getter/adders:units_description_adder",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
])