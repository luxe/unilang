package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "f2si_c_exporter", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/structure/print:file_printer",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_printer",
"//code/transcompilers/unilang/structure/adjust:structure_adjuster",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_c_options_getter",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/test-wrapper-printer:test_wrapper_alias_helper_printer",
"//code/transcompilers/unilang/structure/adjust/methods/creating_methods:extra_methods_creator",
"//code/transcompilers/unilang/structure/model:inlined_structures",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])

hcp(name = "f2si_contributors_getter", deps = [
"//code/transcompilers/unilang/contributor:contributor"
])

hcp(name = "f2si_c_options_getter", deps = [
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/transcompilers/unilang/structure/model:structure",
"//code/utilities/exits:lib",
])

hcp(name = "uber_contributors_getter", deps = [
"//code/transcompilers/unilang/contributor:contributor"
])

hcp(name = "bazel_options_getter", deps = [
    "//code/transcompilers/unilang/options/bazel:build_rule_settings",
    "//code/utilities/life:company_getter"
])

hcp(name = "file_transferer", deps = [
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transfer_action",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transferer",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_action_getter",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/system:lib",
"//code/utilities/types/strings/transformers/removing:lib",
])

hcp(name = "file_transfer_settings_getter", deps = [
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:transfer_account_settings",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/system:lib",
])

