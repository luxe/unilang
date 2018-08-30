package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "cpp_test_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/options/language-specific:cpp_test_export_settings",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/transcompilers/unilang/structure-adjuster:structure_adjuster",
"//code/transcompilers/unilang/structure-printer:file_printer",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
"//code/utilities/converters:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/boilerplate_printer:boilerplate_printer",
"//code/transcompilers/unilang/structure-printer:namespace_printer",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/compiler-frontends/cpp_test:test_coverage_summary_getter",
])

hcp(name = "cpp_test_options_getter", deps = [
"//code/transcompilers/unilang/options/language-specific:cpp_test_export_settings",
"//code/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/transcompilers/unilang/structure:structure",
"//code/utilities/exits:lib",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/transcompilers/unilang/structure-printer/filename:file_name_getter",
])

hcp(name = "test_coverage_summary_getter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:cpp_test_export_settings",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/utilities/converters:lib",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/char:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/transcompilers/unilang/normal-design-printer:method_sorter",
"//code/utilities/types/strings/transformers/inflection/settings:inflection_settings",
"//code/utilities/types/strings/transformers/inflection:inflection_converter",
"//code/utilities/types/strings/transformers/inflection/getters:inflection_settings_getter",
"//code/transcompilers/unilang/normal-design-printer/data:subgroup_methods",
])