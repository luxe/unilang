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

hcp(name = "f2si_cpp_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_c_options_getter",
])

hcp(name = "f2si_c_sharp_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
])

hcp(name = "f2si_d_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
])

hcp(name = "f2si_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/user-frontend/command_line_arguments:user_chosen_export_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_c_exporter",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_cpp_exporter",
"//code/transcompilers/unilang/compiler-frontends/plant_uml_exporter:plant_uml_exporter",
"//code/transcompilers/unilang/compiler-frontends/call_graph_exporter:call_graph_exporter",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_d_exporter",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_rust_exporter",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_c_sharp_exporter",
"//code/transcompilers/unilang/compiler-frontends/text_exporter:text_exporter",
])

hcp(name = "f2si_rust_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
])

hcp(name = "uber_contributors_getter", deps = [
"//code/transcompilers/unilang/contributor:contributor"
])

hcp(name = "uber_cpp_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
])

hcp(name = "uber_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/user-frontend/command_line_arguments:user_chosen_export_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler:uber_hidl_exporter",
"//code/transcompilers/unilang/f2si_frontend_compiler:uber_cpp_exporter",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/transcompilers/unilang/compiler-frontends/plant_uml_exporter:plant_uml_exporter",
"//code/transcompilers/unilang/compiler-frontends/treesheets:treesheets_exporter",
"//code/transcompilers/unilang/compiler-frontends/html_table:html_table_exporter",
])

hcp(name = "uber_hidl_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/options/language-specific:hidl_export_settings",
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transfer_action",
"//code/transcompilers/unilang/structure-printer:file_printer",
"//code/transcompilers/unilang/structure-adjuster:structure_adjuster",
"//code/transcompilers/unilang/f2si_frontend_compiler:uber_hidl_options_getter",
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
])

hcp(name = "uber_hidl_options_getter", deps = [
"//code/transcompilers/unilang/options/language-specific:hidl_export_settings",
"//code/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/transcompilers/unilang/structure:structure",
"//code/utilities/exits:lib",
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
])

