package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "structure_name_kind")

hcp(
    name = "struct_name_deriver",
    deps = [
        "//code/utilities/types/strings/transformers/casing:case_modifier",
    ],
)

hcp(
    name = "type_name_deriver",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_argument",
        "//code/tools/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_result",
        "//code/tools/transcompilers/unilang/structure/model/sections/typedef:typedef_argument",
        "//code/tools/transcompilers/unilang/structure/model/sections/typedef:typedef_result",
        "//code/tools/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:stripped_unilang_type_with_qualifiers",
        "//code/tools/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
        "//code/utilities/linguistics/computer/types/cross/language_type",
        "//code/utilities/linguistics/computer/types/generic:unilang_type_to_language_type_converter",
        "//code/utilities/types/converters:lib",
    ],
)

hcp(
    name = "structure_typename_deriver",
    deps = [
        "//code/tools/transcompilers/unilang/structure/print/derivers:structure_name_kind",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)

hcp(
    name = "identifier_name_deriver",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/options/sections:notation_settings",
        "//code/tools/transcompilers/unilang/options/self_describe_type:modify_identifier_with_extra_type_info",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_argument",
        "//code/tools/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_result",
        "//code/tools/transcompilers/unilang/structure/print:shared_printer",
        "//code/tools/transcompilers/unilang/type_converters/type_to_hungarian:data_member_to_hungarian_notation_converter",
        "//code/utilities/linguistics/computer/types/generic:unilang_type_to_language_type_converter",
        "//code/utilities/types:tri_bool",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/units:unit_suffix_lookuper",
        "//code/utilities/units:units_to_variable_suffix_lookup_table",
    ],
)
