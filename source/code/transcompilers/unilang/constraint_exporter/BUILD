package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "value_constraints_to_interval_constraints", deps = [
"//code/transcompilers/unilang/constraint_exporter/interval_constraint:interval_constraint",
"//code/transcompilers/unilang/structure/sections/data_member:value_constraints",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/observers/char:lib",
"//code/utilities/types/wstrings/transformers/other:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/observers/other:lib",
])

hcp(name = "concise_constraint_exporter", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/constraint_exporter/interval_constraint:interval_constraint",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/transcompilers/unilang/constraint_exporter:concise_constraint_line_exporter",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/utilities/filesystem/files/transformers:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
])

hcp(name = "concise_constraint_line_exporter", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/constraint_exporter/interval_constraint:interval_constraint",
"value_constraints_to_interval_constraints",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/transcompilers/unilang/structure:inlined_structures",
])

hcp(name = "if_chain_constraint_exporter", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/structure-printer/derivers:identifier_name_deriver",
"//code/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/transcompilers/unilang/structure:inlined_structures",
])

hcp(name = "constraint_exporter", deps = [
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/constraint_exporter:concise_constraint_exporter",
"//code/transcompilers/unilang/constraint_exporter:if_chain_constraint_exporter",
"//code/transcompilers/unilang/structure:inlined_structures",
])