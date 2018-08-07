package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "component_input", deps = [
"//code/transcompilers/unilang/structure/sections/method/arguments/argument:function_argument"
])

hcp(name = "component_output", deps = [
"//code/transcompilers/unilang/structure/sections/method/arguments/argument:function_result"
])

hcp(name = "input_struct_getter", deps = [
"component_input",
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/utilities/converters:lib",
])

hcp(name = "object_name_resolver", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "component_struct_printer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/structure-printer:doxygen_block_printer",
"//code/transcompilers/unilang/type_converters/type_to_hungarian:type_to_hungarian_notation_converter",
"//code/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
"component_input",
"component_output",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/in-out-design-printer:input_struct_getter",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/enum_printer:enum_section_printer",
"//code/transcompilers/unilang/structure/sections/enum/item:enum_item",
"//code/transcompilers/unilang/structure-printer:data_member_printer",
"//code/transcompilers/unilang/structure-printer/derivers:structure_typename_deriver",
"//code/transcompilers/unilang/structure-printer:struct_printer",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/streams/filestreams:lib",
])

hcp(name = "api_printer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
"//code/utilities/types/vectors/transformers:lib",
])

hcp(name = "in_out_design_printer", deps = [
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer/macro:macro_printer",
"//code/transcompilers/unilang/in-out-design-printer:component_struct_printer",
])