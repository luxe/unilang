package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "update_with_bools_printer", deps = [
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/print:methods_printer",
"//code/transcompilers/unilang/structure/print:shared_printer",
"//code/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "update_with_enums_printer", deps = [
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/control-structure-printer/switch:switch_block",
"//code/transcompilers/unilang/structure/print:shared_printer",
"//code/transcompilers/unilang/control-structure-printer/switch:switch_block_printer",
"//code/transcompilers/unilang/structure/print:methods_printer",
"//code/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "update_printer", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/print:methods_printer",
"//code/transcompilers/unilang/parser/body_parser:body_token_value",
"//code/transcompilers/unilang/structure/print:shared_printer",
"update_with_bools_printer",
"update_with_enums_printer",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/streams/filestreams:lib",
])