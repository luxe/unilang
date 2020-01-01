package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "shared_printer", deps = [
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/observers/comparing:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/transformers/removing:lib",
])

hcp(name = "stream_creator", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/filesystem:general_filesystem_naming",
"//code/transcompilers/unilang/structure/print/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/structure/print/filename:file_name_getter",
])

cpp_object(name = "function_declaration_location")

hcp(name = "doxygen_block_printer", deps = [
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data_getter",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/streams/filestreams:lib",
])

hcp(name = "data_member_printer", deps = [
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/structure/print:shared_printer",
"//code/transcompilers/unilang/literal_suffix_getter/getter:literal_suffix_settings",
"//code/transcompilers/unilang/literal_suffix_getter/getter:literal_suffix_getter",
"//code/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/transcompilers/unilang/structure/print/derivers:type_name_deriver",
"//code/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_dresser",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
"//code/utilities/converters:lib",
"//code/utilities/streams/filestreams:lib",
])

hcp(name = "method_body_token_printer", deps = [
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/streams/filestreams:lib",
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/in-method-printers:body_param_in_method_printer",
"//code/transcompilers/unilang/in-method-printers:data_member_in_method_printer",
"//code/transcompilers/unilang/in-method-printers:method_call_in_method_printer",
"//code/transcompilers/unilang/in-method-printers:foreign_method_call_in_method_printer",
"//code/transcompilers/unilang/comment_creator:comment_creator",
"//code/utilities/types/variant:lib",
])

hcp(name = "namespace_printer", deps = [
"//code/transcompilers/unilang/structure/model/sections/namespace:namespace_section",
"//code/transcompilers/unilang/options/sections/namespace:namespace_options",
"//code/transcompilers/unilang/structure/model/sections/namespace:namespace_item",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data_getter",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "return_type_str_getter", deps = [
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/structure/print:shared_printer",
"//code/transcompilers/unilang/structure/print/derivers:type_name_deriver",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_dresser",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "method_block_ender", deps = [
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/structure/print:shared_printer",
"//code/transcompilers/unilang/comment_creator:comment_creator",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "implicit_contract_adder", deps = [
"//code/transcompilers/unilang/structure/model/sections/method/contracts:method_contracts_section",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "methods_printer", deps=[
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/tokens:token_name",
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/structure/print:function_declaration_location",
"//code/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/transcompilers/unilang/design/in-out:input_struct_getter",
"//code/transcompilers/unilang/structure/print:method_body_token_printer",
"//code/transcompilers/unilang/structure/print:shared_printer",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/structure/print/attributes:method_attributes_getter",
"//code/transcompilers/unilang/structure/print/derivers:type_name_deriver",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_dresser",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
"//code/transcompilers/unilang/structure/print:return_type_str_getter",
"//code/transcompilers/unilang/structure/print:method_block_ender",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/transcompilers/unilang/structure/print:method_signature_printer",
])

hcp(name = "method_signature_printer", deps=[
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/tokens:token_name",
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/structure/print:function_declaration_location",
"//code/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/transcompilers/unilang/design/in-out:input_struct_getter",
"//code/transcompilers/unilang/structure/print:method_body_token_printer",
"//code/transcompilers/unilang/structure/print:shared_printer",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/structure/print/attributes:method_attributes_getter",
"//code/transcompilers/unilang/structure/print/derivers:type_name_deriver",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_dresser",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
"//code/transcompilers/unilang/structure/print:return_type_str_getter",
"//code/transcompilers/unilang/structure/print:method_block_ender",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "struct_printer", deps = [
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_section",
"//code/transcompilers/unilang/structure/model/sections/types:type_section",
"//code/transcompilers/unilang/options/sections:portion_options",
"//code/transcompilers/unilang/options:general_options",
"//code/transcompilers/unilang/structure/print:data_member_printer",
"//code/transcompilers/unilang/structure/print:hidl_data_member_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/transcompilers/unilang/structure/print:struct_derivers",
])

hcp(name="hidl_data_member_printer", deps = [
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_section",
"//code/transcompilers/unilang/structure/model/sections/types:type_section",
"//code/transcompilers/unilang/options/sections:portion_options",
"//code/transcompilers/unilang/options:general_options",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter:unilang_type_to_language_type_converter",
"//code/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/transcompilers/unilang/structure/print/derivers:type_name_deriver",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "object_printer", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"object_file_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "object_file_printer", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/print/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/boilerplate_printer:boilerplate_printer",
"//code/transcompilers/unilang/design/normal:normal_design_printer",
"//code/transcompilers/unilang/design/in-out:in_out_design_printer",
"//code/transcompilers/unilang/structure/print:stream_creator",
"//code/transcompilers/unilang/structure/print:actual_structure_printer",
"//code/transcompilers/unilang/structure/print/filename:file_name_getter",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "actual_structure_printer", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/print/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/design/normal:normal_design_printer",
"//code/transcompilers/unilang/design/in-out:in_out_design_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/transcompilers/unilang/structure/model:inlined_structures",
])

hcp(name = "global_printer", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/structure/print/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/print:stream_creator",
"//code/transcompilers/unilang/boilerplate_printer/meta_block:meta_block_printer",
"//code/transcompilers/unilang/boilerplate_printer:code_wrap_printer",
"//code/transcompilers/unilang/boilerplate_printer/header:header_printer",
"//code/transcompilers/unilang/structure/print/macro:macro_printer",
"//code/transcompilers/unilang/enum_printer:enum_section_printer",
"//code/transcompilers/unilang/structure/print:data_member_printer",
"//code/transcompilers/unilang/structure/print/typedef:typedef_printer",
"//code/transcompilers/unilang/structure/print:methods_printer",
"//code/transcompilers/unilang/boilerplate_printer/extern_c:extern_wrap_printer",
"//code/transcompilers/unilang/boilerplate_printer:boilerplate_printer",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/structure/print:actual_structure_printer",
"//code/transcompilers/unilang/structure/print/filename:file_name_getter",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/transcompilers/unilang/options/language-specific:cpp_export_settings",
"//code/utilities/types/vectors/operators:lib",
"//code/transcompilers/unilang/structure/print:namespace_printer",
"//code/transcompilers/unilang/design/normal:method_sorting_and_grouping_order_printer",
"//code/transcompilers/unilang/structure/print/table_of_contents:function_table_of_contents_printer",
])

hcp(name = "file_printer", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/print:global_printer",
"//code/transcompilers/unilang/structure/print:object_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/transcompilers/unilang/options/language-specific:cpp_export_settings",
"//code/utilities/types/vectors/operators:lib",
])

hcp(name = "struct_derivers", deps = [
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_section",
"//code/transcompilers/unilang/structure/model/sections/types:type_section",
"//code/utilities/converters:lib",
"//code/transcompilers/unilang/structure/model/sections/enum:enum_section",
])

