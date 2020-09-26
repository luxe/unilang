package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "transition_function_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_language_version",
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_data_member:data_member_utility_function_options",
        "//code/tools/transcompilers/unilang/options/sections/data_member:data_member_options",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters:boolean_expression_creator",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters/printf:printf_code_generator",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
        "//code/tools/transcompilers/unilang/type_converters/special-type-to-comparison:special_type_comparison_getter",
        "//code/tools/transcompilers/unilang/type_converters/special-type-to-comparison/settings:special_comparison_type",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
