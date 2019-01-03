package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "implicit_global_header_comment_deriver", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings"
])

hcp(name = "header_collector", deps = [
"//code/transcompilers/unilang/structure/sections/import:import_section",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/transcompilers/unilang/structure-printer/filename:file_name_getter",
"//code/transcompilers/unilang/boilerplate_printer/header/unilang-convert:header_extension_deriver",
"//code/transcompilers/unilang/boilerplate_printer/header:implicit_global_header_comment_deriver",
"//code/transcompilers/unilang/boilerplate_printer/header/relationships:import_relationship_comment_deriver",
"//code/transcompilers/unilang/comment_creator:comment_creator",
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/sets:lib",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])

hcp(name = "header_printer", deps = [
"//code/transcompilers/unilang/structure/sections/import:import_section",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/options/language-specific:hidl_export_settings",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/transcompilers/unilang/boilerplate_printer/header/unilang-convert:header_adjuster",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/structure-printer/filename:file_name_getter",
"//code/transcompilers/unilang/boilerplate_printer/header:header_collector",
"//code/transcompilers/unilang/boilerplate_printer/header/block:header_block_comment_getter",
"//code/transcompilers/unilang/comment_creator:comment_creator",
"//code/utilities/streams/filestreams:lib",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])