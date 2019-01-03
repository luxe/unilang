package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "transition_function_getter", deps = [
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/sections/data_member:data_member_options",
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/options/manipulation/methods/via_data_member:data_member_utility_function_options",
"//code/transcompilers/unilang/options/language-specific:c_language_version",
"//code/transcompilers/unilang/type_converters/special-type-to-comparison/settings:special_comparison_type",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/type_converters/special-type-to-comparison:special_type_comparison_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_data_members/individual_getters/printf:printf_code_generator",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_data_members/individual_getters:boolean_expression_creator",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/vectors/operators:lib",
])