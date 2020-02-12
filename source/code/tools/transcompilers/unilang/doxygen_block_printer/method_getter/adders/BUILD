package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name= "units_description_adder", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/tools/transcompilers/unilang/doxygen_block_printer:value_constraint_comment_deriver",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/tools/transcompilers/unilang/units_to_variable_suffix_converter:unit_suffix_lookuper",
"//code/tools/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/utilities/types/converters:lib",
])

hcp(name = "return_results_description_adder", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/tools/transcompilers/unilang/doxygen_block_printer/method_getter/adders:units_description_adder",
"//code/utilities/types/converters:lib",
])

hcp(name = "suggested_return_identifier_adder", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/tools/transcompilers/unilang/doxygen_block_printer/method_getter/adders:units_description_adder",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/utilities/types/converters:lib",
])

hcp(name = "main_description_adder", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/tools/transcompilers/unilang/doxygen_block_printer:value_constraint_comment_deriver",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/tools/transcompilers/unilang/units_to_variable_suffix_converter:unit_suffix_lookuper",
"//code/tools/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/utilities/types/converters:lib",
])

hcp(name = "contract_description_adder", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/tools/transcompilers/unilang/doxygen_block_printer:value_constraint_comment_deriver",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/tools/transcompilers/unilang/units_to_variable_suffix_converter:unit_suffix_lookuper",
"//code/tools/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/utilities/types/converters:lib",

])

hcp(name = "argument_description_adder", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/tools/transcompilers/unilang/doxygen_block_printer:value_constraint_comment_deriver",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/tools/transcompilers/unilang/units_to_variable_suffix_converter:unit_suffix_lookuper",
"//code/tools/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/tools/transcompilers/unilang/doxygen_block_printer/method_getter/adders:units_description_adder",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/tools/transcompilers/unilang/options/comment/doxygen:doxygen_parameter_direction",
"//code/tools/transcompilers/unilang/structure/query:argument_direction_decider",
])

hcp(name = "overload_note_adder", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
"//code/tools/transcompilers/unilang/structure/query:is_overload_decider",
])