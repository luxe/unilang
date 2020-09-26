package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "enum_utility_function_shared",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
        "//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)

hcp(
    name = "enum_utility_function_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/enum_to_str:enum_to_str_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/enum_to_str:enum_to_str_inflection_count_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/enum_to_str:enum_to_str_plural_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/enum_to_str:enum_to_str_singular_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/iteration:enum_next_function_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/iteration:enum_previous_function_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/str_to_enum:str_plural_to_enum_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/str_to_enum:str_singular_to_enum_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/str_to_enum:str_to_enum_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/subgroup_affiliation:enum_subgroup_affiliation_function_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/value:enum_first_function_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/value:enum_last_function_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum/individual_getters/value:enum_total_function_getter",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
        "//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
        "//code/tools/transcompilers/unilang/structure/print:function_declaration_location",
        "//code/tools/transcompilers/unilang/structure/print:methods_printer",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)
