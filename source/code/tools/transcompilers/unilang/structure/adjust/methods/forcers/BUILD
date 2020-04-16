package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "method_chaining_enforcer", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/types/converters:lib",
])

hcp(name = "method_overload_adjuster", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/types/converters:lib",
])

hcp(name = "return_statement_enforcer", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/types/converters:lib",
])

hcp(name = "immutable_value_to_immutable_ref_adjuster", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/types/converters:lib",
"//code/utilities/linguistics/computer/types/generic:unilang_type_to_language_type_converter",
])

hcp(name = "instantiate_and_return_injector_for_return_type", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/types/converters:lib",
"//code/utilities/linguistics/computer/types/generic:unilang_type_to_language_type_converter",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/vectors/transformers:lib",
"//code/tools/transcompilers/unilang/structure/print/derivers:type_name_deriver",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/utilities/types/variant:lib",
"//code/utilities/types/strings/observers/char:lib",
])





hcp(name = "function_unit_test_name_defaulter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/types/converters:lib",
])

hcp(name = "methods_sorter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/utilities/types/converters:lib",
])
