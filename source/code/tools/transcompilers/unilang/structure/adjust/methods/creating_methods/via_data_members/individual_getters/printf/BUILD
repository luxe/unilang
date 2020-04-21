package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "printf_statement_kind")

hcp(name = "printf_code_generator", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/sections/data_member:data_member_options",
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/options/manipulation/methods/via_data_member:data_member_utility_function_options",
"//code/tools/transcompilers/unilang/type_converters/special-type-to-printf/settings:special_printf_type",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_language_version",
"//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters/printf:printf_statement_kind",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/type_converters/type-to-printf-specifier:printf_specifier_getter",
"//code/tools/transcompilers/unilang/type_converters/special-type-to-printf:special_type_printf_specifier_getter",
"//code/tools/transcompilers/unilang/type_converters/type-to-printf-specifier/settings:printf_specifier_settings",
"//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters/printf/specific:printf_print_statement_creator",
"//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters/printf/specific:printf_transition_statement_creator",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/observers/other:lib",
])