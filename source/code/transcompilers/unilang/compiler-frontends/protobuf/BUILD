package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "protobuf_exporter", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/options/language-specific/protocol_buffer_settings:protocol_buffer_export_settings",
"//code/transcompilers/unilang/structure/print/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transfer_action",
"//code/transcompilers/unilang/structure/print:file_printer",
"//code/transcompilers/unilang/structure/adjust:structure_adjuster",
"//code/transcompilers/unilang/compiler-frontends/protobuf:protobuf_options_getter",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/structure/model/sections/meta:code_type",
"//code/transcompilers/unilang/structure/print:stream_creator",
"//code/transcompilers/unilang/structure/print/filename:file_name_getter",
"//code/transcompilers/unilang/boilerplate_printer:boilerplate_printer",
"//code/transcompilers/unilang/boilerplate_printer:code_wrap_printer",
"//code/transcompilers/unilang/enum_printer:enum_section_printer",
"//code/transcompilers/unilang/structure/print:namespace_printer",
"//code/transcompilers/unilang/boilerplate_printer/header:header_printer",
"//code/transcompilers/unilang/structure/print:struct_printer",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transferer",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/transcompilers/unilang/f2si_frontend_compiler:file_transferer",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/char:lib",
])

hcp(name = "protobuf_options_getter", deps = [
"//code/transcompilers/unilang/options/language-specific/protocol_buffer_settings:protocol_buffer_export_settings",
"//code/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/transcompilers/unilang/structure/model:structure",
"//code/utilities/exits:lib",
"//code/utilities/life:company_getter",
])
