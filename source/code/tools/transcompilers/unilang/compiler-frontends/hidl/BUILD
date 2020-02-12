package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "hidl_exporter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/contributor:contributor",
"//code/tools/transcompilers/unilang/options/language-specific:hidl_export_settings",
"//code/tools/transcompilers/unilang/structure/print/export_file_settings:export_file_settings",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transfer_action",
"//code/tools/transcompilers/unilang/structure/print:file_printer",
"//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
"//code/tools/transcompilers/unilang/compiler-frontends/hidl:hidl_options_getter",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/tools/transcompilers/unilang/structure/print:stream_creator",
"//code/tools/transcompilers/unilang/structure/print/filename:file_name_getter",
"//code/tools/transcompilers/unilang/boilerplate_printer:boilerplate_printer",
"//code/tools/transcompilers/unilang/boilerplate_printer:code_wrap_printer",
"//code/tools/transcompilers/unilang/enum_printer:enum_section_printer",
"//code/tools/transcompilers/unilang/structure/print:namespace_printer",
"//code/tools/transcompilers/unilang/boilerplate_printer/header:header_printer",
"//code/tools/transcompilers/unilang/structure/print:struct_printer",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transferer",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler:file_transferer",
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])

hcp(name = "hidl_options_getter", deps = [
"//code/tools/transcompilers/unilang/options/language-specific:hidl_export_settings",
"//code/tools/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/utilities/program/common_actions/exits:lib",
"//code/utilities/personal/life:company_getter",
])
