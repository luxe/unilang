package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "good_api_creator", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/print:methods_printer",
"//code/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/structure/print:shared_printer",
"//code/transcompilers/unilang/structure/print:implicit_contract_adder",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "deep_copy_creator", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/print:implicit_contract_adder",
"//code/transcompilers/unilang/design/in-out:object_name_resolver",
"//code/transcompilers/unilang/structure/print:methods_printer",
"//code/transcompilers/unilang/structure/print:shared_printer",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])