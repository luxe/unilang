package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

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
])

hcp(name = "cpp_test_options_getter", deps = [
"//code/transcompilers/unilang/options/language-specific:cpp_test_export_settings",
"//code/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/transcompilers/unilang/structure:structure",
"//code/utilities/exits:lib",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/transcompilers/unilang/structure-printer/filename:file_name_getter",
])