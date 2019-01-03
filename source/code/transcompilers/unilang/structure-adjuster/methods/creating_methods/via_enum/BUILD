package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "enum_utility_function_shared", deps = [
"//code/transcompilers/unilang/structure/sections/enum/item:enum_item",
"//code/transcompilers/unilang/options/sections/enum:enum_options",
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/converters:lib"
])

hcp(name = "enum_utility_function_getter", deps = [
"//code/transcompilers/unilang/structure/sections/enum/item:enum_item",
"//code/transcompilers/unilang/options/sections/enum:enum_options",
"//code/transcompilers/unilang/structure-printer:doxygen_block_printer",
"//code/transcompilers/unilang/structure-printer:function_declaration_location",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure/sections/meta:code_type",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/converters:lib",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/value:enum_first_function_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/value:enum_last_function_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/value:enum_total_function_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/iteration:enum_next_function_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/iteration:enum_previous_function_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/enum_to_str:enum_to_str_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/enum_to_str:enum_to_str_singular_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/enum_to_str:enum_to_str_plural_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/enum_to_str:enum_to_str_inflection_count_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/str_to_enum:str_to_enum_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/str_to_enum:str_singular_to_enum_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/str_to_enum:str_plural_to_enum_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum/individual_getters/subgroup_affiliation:enum_subgroup_affiliation_function_getter",
])