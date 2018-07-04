package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "test_wrapper_utilities", deps = [
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/transformers/appending:lib",
])

hcp(name = "va_list_part_getter", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/utilities/types/vectors/observers:lib",
])

hcp(name = "wrapper_interface_printer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:stream_creator",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_methods_printer",
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/structure-printer/derivers:type_name_deriver",
"//code/transcompilers/unilang/structure-printer:data_member_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "wrapper_source_printer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure-printer:stream_creator",
"//code/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_methods_printer",
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "in_out_design_test_wrapper_printer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"wrapper_interface_printer",
"wrapper_source_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
])

hcp(name = "normal_design_test_wrapper_printer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"wrapper_interface_printer",
"wrapper_source_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
])

hcp(name = "test_wrapper_alias_helper_printer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
])

hcp(name = "test_wrapper_method_shared", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
])

hcp(name = "test_wrapper_methods_printer", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/in-out-design-printer:input_struct_getter",
"//code/transcompilers/unilang/structure-printer:doxygen_block_printer",
"//code/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/transcompilers/unilang/structure/sections/meta:code_type",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_special_method_printer",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_method_shared",
"//code/transcompilers/unilang/structure-printer/derivers:type_name_deriver",
"//code/transcompilers/unilang/structure-printer:return_type_str_getter",
"//code/transcompilers/unilang/structure-printer:function_declaration_location",
"va_list_part_getter",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib"
])

hcp(name = "test_wrapper_printer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"normal_design_test_wrapper_printer",
"in_out_design_test_wrapper_printer",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/observers/comparing:lib",
])

hcp(name = "test_wrapper_special_method_printer", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/in-out-design-printer:input_struct_getter",
"//code/transcompilers/unilang/structure-printer:doxygen_block_printer",
"//code/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/transcompilers/unilang/structure/sections/meta:code_type",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_method_shared",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])
