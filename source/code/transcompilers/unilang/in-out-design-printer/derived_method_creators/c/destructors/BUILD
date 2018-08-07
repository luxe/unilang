package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "destructor_creator", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure/sections/meta:code_type",
"//code/transcompilers/unilang/structure-printer:implicit_contract_adder",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "forwarded_destructor_creator", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure/sections/meta:code_type",
"//code/transcompilers/unilang/structure-printer:implicit_contract_adder",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])