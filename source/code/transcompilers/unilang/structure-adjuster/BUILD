package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "comment_adjuster", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/transcompilers/unilang/options/comment:comment_grammar_settings",
"//code/transcompilers/unilang/options/manipulation/reflow:comment_reflow_settings",
"//code/transcompilers/unilang/structure-adjuster:words_deriver",
"//code/transcompilers/unilang/parser:token_value",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/transcompilers/unilang/structure-adjuster:greedy_reflower",
])

hcp(name = "words_deriver", deps = [
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/strings/observers/char:lib",
])

hcp(name = "module_dependency_resolver", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/structure-printer/export_file_settings:file_type",
])

hcp(name = "structure_adjuster", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/structure-adjuster/meta:meta_adjuster",
"//code/transcompilers/unilang/structure-adjuster/types:type_adjuster",
"//code/transcompilers/unilang/structure-adjuster/imports:import_adjuster",
"//code/transcompilers/unilang/structure-adjuster/enums:enums_adjuster",
"//code/transcompilers/unilang/structure-adjuster/methods:methods_adjuster",
"//code/transcompilers/unilang/structure-adjuster/data_members:data_member_adjuster",
"structure_normalizer",
"module_dependency_resolver",
"//code/utilities/types/strings/observers/converting:lib",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])

hcp(name = "structure_normalizer", deps = [
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/converters:lib",
"//code/transcompilers/unilang/structure:structure",
])

hcp(name = "casing_adjuster", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/transcompilers/unilang/structure-printer:struct_derivers",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/shell:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/options/manipulation:case_adjustment_settings",
])

hcp(name = "greedy_reflower", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/transcompilers/unilang/options/comment:comment_grammar_settings",
"//code/transcompilers/unilang/options/manipulation/reflow:greedy_reflow_settings",
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure-adjuster:words_deriver",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
])

hcp(name = "knuth_plass_entry", deps = [])
hcp(name = "knuth_plass_reflower", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/doxygen_block_printer:grammar_adjuster",
"//code/transcompilers/unilang/options/comment:comment_grammar_settings",
"//code/transcompilers/unilang/options/manipulation/reflow:knuth_plass_reflow_settings",
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure-adjuster:knuth_plass_entry",
"//code/transcompilers/unilang/structure-adjuster:words_deriver",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
])