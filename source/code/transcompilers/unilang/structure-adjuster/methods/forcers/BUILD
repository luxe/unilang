package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "method_chaining_enforcer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/converters:lib",
])

hcp(name = "method_overload_adjuster", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/converters:lib",
])

hcp(name = "return_statement_enforcer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/converters:lib",
])

hcp(name = "immutable_value_to_immutable_ref_adjuster", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/converters:lib",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter:unilang_type_to_language_type_converter",
])

hcp(name = "instantiate_and_return_injector_for_return_type", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/converters:lib",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter:unilang_type_to_language_type_converter",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/vectors/transformers:lib",
"//code/transcompilers/unilang/structure-printer/derivers:type_name_deriver",
])

hcp(name = "function_unit_test_name_defaulter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/converters:lib",
])
