package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "test_wrapper_utilities", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/transformers/appending:lib",
])

hcp(name = "va_list_part_getter", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/utilities/types/vectors/observers:lib",
])

hcp(name = "wrapper_interface_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:stream_creator",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/tools/transcompilers/unilang/structure/print:methods_printer",
"//code/tools/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_methods_printer",
"//code/tools/transcompilers/unilang/structure/print/export_file_settings:export_file_settings",
"//code/tools/transcompilers/unilang/structure/print/derivers:type_name_deriver",
"//code/tools/transcompilers/unilang/structure/print:data_member_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "wrapper_source_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:methods_printer",
"//code/tools/transcompilers/unilang/structure/print:stream_creator",
"//code/tools/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_methods_printer",
"//code/tools/transcompilers/unilang/structure/print/export_file_settings:export_file_settings",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "in_out_design_test_wrapper_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"wrapper_interface_printer",
"wrapper_source_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
])

hcp(name = "normal_design_test_wrapper_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"wrapper_interface_printer",
"wrapper_source_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
])

hcp(name = "test_wrapper_alias_helper_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
])

hcp(name = "test_wrapper_method_shared", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
])

hcp(name = "test_wrapper_methods_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:methods_printer",
"//code/tools/transcompilers/unilang/design/in-out:input_struct_getter",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/tools/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_special_method_printer",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_method_shared",
"//code/tools/transcompilers/unilang/structure/print/derivers:type_name_deriver",
"//code/tools/transcompilers/unilang/structure/print:return_type_str_getter",
"//code/tools/transcompilers/unilang/structure/print:function_declaration_location",
"//code/tools/transcompilers/unilang/structure/print:method_signature_printer",
"va_list_part_getter",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib"
])

hcp(name = "test_wrapper_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"normal_design_test_wrapper_printer",
"in_out_design_test_wrapper_printer",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/observers/comparing:lib",
])

hcp(name = "test_wrapper_special_method_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:methods_printer",
"//code/tools/transcompilers/unilang/design/in-out:input_struct_getter",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/tools/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_utilities",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_method_shared",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])
