package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "f2si_c_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/structure-printer:file_printer",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_printer",
"//code/transcompilers/unilang/structure-adjuster:structure_adjuster",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_c_options_getter",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_alias_helper_printer",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods:extra_methods_creator",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])

hcp(name = "f2si_contributors_getter", deps = [
"//code/transcompilers/unilang/contributor:contributor"
])

hcp(name = "f2si_c_options_getter", deps = [
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/transcompilers/unilang/structure:structure",
"//code/utilities/exits:lib",
])

hcp(name = "cpp_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/options/language-specific:cpp_export_settings",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/transcompilers/unilang/structure-adjuster:structure_adjuster",
"//code/transcompilers/unilang/structure-printer:file_printer",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])

hcp(name = "uber_contributors_getter", deps = [
"//code/transcompilers/unilang/contributor:contributor"
])

hcp(name = "hidl_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/options/language-specific:hidl_export_settings",
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transfer_action",
"//code/transcompilers/unilang/structure-printer:file_printer",
"//code/transcompilers/unilang/structure-adjuster:structure_adjuster",
"//code/transcompilers/unilang/f2si_frontend_compiler:hidl_options_getter",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/structure/sections/meta:code_type",
"//code/transcompilers/unilang/structure-printer:stream_creator",
"//code/transcompilers/unilang/structure-printer/filename:file_name_getter",
"//code/transcompilers/unilang/boilerplate_printer:boilerplate_printer",
"//code/transcompilers/unilang/boilerplate_printer:code_wrap_printer",
"//code/transcompilers/unilang/enum_printer:enum_section_printer",
"//code/transcompilers/unilang/structure-printer:namespace_printer",
"//code/transcompilers/unilang/boilerplate_printer/header:header_printer",
"//code/transcompilers/unilang/structure-printer:struct_printer",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transferer",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/transcompilers/unilang/f2si_frontend_compiler:file_transferer",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])

hcp(name = "hidl_options_getter", deps = [
"//code/transcompilers/unilang/options/language-specific:hidl_export_settings",
"//code/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/transcompilers/unilang/structure:structure",
"//code/utilities/exits:lib",
])

hcp(name = "cpp_options_getter", deps = [
"//code/transcompilers/unilang/options/language-specific:cpp_export_settings",
"//code/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/transcompilers/unilang/structure:structure",
"//code/utilities/exits:lib",
"//code/transcompilers/unilang/structure:inlined_structures",
])

hcp(name = "bazel_options_getter", deps = [
    "//code/transcompilers/unilang/options/bazel:build_rule_settings",
])

hcp(name = "file_transferer", deps = [
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transfer_action",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transferer",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/system:lib",
])

hcp(name = "file_transfer_settings_getter", deps = [
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:transfer_account_settings",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/system:lib",
])

