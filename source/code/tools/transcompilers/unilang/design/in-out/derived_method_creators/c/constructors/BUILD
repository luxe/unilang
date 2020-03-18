package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "copy_constructor_creator", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:implicit_contract_adder",
"//code/tools/transcompilers/unilang/structure/print:methods_printer",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "forwarded_copy_constructor_creator", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:implicit_contract_adder",
"//code/tools/transcompilers/unilang/structure/print:methods_printer",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "initialize_creator", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:methods_printer",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/tools/transcompilers/unilang/design/in-out:object_name_resolver",
"//code/tools/transcompilers/unilang/structure/print:implicit_contract_adder",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "shortcut_constructor_creator", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:implicit_contract_adder",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/tools/transcompilers/unilang/design/in-out:object_name_resolver",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])


hcp(name = "shortcut_copy_constructor_creator", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:implicit_contract_adder",
"//code/tools/transcompilers/unilang/structure/print:shared_printer",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/tools/transcompilers/unilang/design/in-out:object_name_resolver",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])
