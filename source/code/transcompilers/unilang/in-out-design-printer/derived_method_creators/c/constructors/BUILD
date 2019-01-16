package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "copy_constructor_creator", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:implicit_contract_adder",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "forwarded_copy_constructor_creator", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:implicit_contract_adder",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "initialize_creator", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/in-out-design-printer:object_name_resolver",
"//code/transcompilers/unilang/structure-printer:implicit_contract_adder",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "shortcut_constructor_creator", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:implicit_contract_adder",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/in-out-design-printer:object_name_resolver",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])


hcp(name = "shortcut_copy_constructor_creator", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:implicit_contract_adder",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/in-out-design-printer:object_name_resolver",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])
