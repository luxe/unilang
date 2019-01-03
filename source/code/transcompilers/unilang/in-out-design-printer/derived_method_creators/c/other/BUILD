package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "good_api_creator", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure-printer:implicit_contract_adder",
"//code/transcompilers/unilang/structure/sections/meta:code_type",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "deep_copy_creator", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:implicit_contract_adder",
"//code/transcompilers/unilang/in-out-design-printer:object_name_resolver",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure/sections/meta:code_type",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])