package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "f2si_c_exporter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/contributor:contributor",
"//code/tools/transcompilers/unilang/structure/print:file_printer",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_printer",
"//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler:f2si_c_options_getter",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/tools/transcompilers/unilang/test-wrapper-printer:test_wrapper_alias_helper_printer",
"//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods:extra_methods_creator",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/linguistics/computer:source_language",
])

hcp(name = "f2si_contributors_getter", deps = [
"//code/tools/transcompilers/unilang/contributor:contributor"
])

hcp(name = "f2si_c_options_getter", deps = [
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/utilities/program/common_actions/exits:lib",
])

hcp(name = "uber_contributors_getter", deps = [
"//code/tools/transcompilers/unilang/contributor:contributor"
])

hcp(name = "bazel_options_getter", deps = [
    "//code/tools/transcompilers/unilang/options/bazel:build_rule_settings",
    "//code/utilities/personal/life:company_getter"
])

hcp(name = "file_transferer", deps = [
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transfer_action",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transferer",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_action_getter",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/system:lib",
"//code/utilities/types/strings/transformers/removing:lib",
])

hcp(name = "file_transfer_settings_getter", deps = [
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:transfer_account_settings",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/system:lib",
])

