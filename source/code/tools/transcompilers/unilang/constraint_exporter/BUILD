package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "value_constraints_to_interval_constraints", deps = [
"//code/tools/transcompilers/unilang/constraint_exporter/interval_constraint:interval_constraint",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:value_constraints",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/observers/char:lib",
"//code/utilities/types/wstrings/transformers/other:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/observers/other:lib",
])

hcp(name = "concise_constraint_exporter", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/contributor:contributor",
"//code/tools/transcompilers/unilang/constraint_exporter/interval_constraint:interval_constraint",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/tools/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/tools/transcompilers/unilang/constraint_exporter:concise_constraint_line_exporter",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
"//code/utilities/filesystem/files/transformers:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
])

hcp(name = "concise_constraint_line_exporter", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/contributor:contributor",
"//code/tools/transcompilers/unilang/constraint_exporter/interval_constraint:interval_constraint",
"value_constraints_to_interval_constraints",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/tools/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
])

hcp(name = "if_chain_constraint_exporter", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/contributor:contributor",
"//code/tools/transcompilers/unilang/structure/print:methods_printer",
"//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
"//code/tools/transcompilers/unilang/literal_suffix_getter/adjuster:literal_adjuster",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
])

hcp(name = "constraint_exporter", deps = [
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/contributor:contributor",
"//code/tools/transcompilers/unilang/constraint_exporter:concise_constraint_exporter",
"//code/tools/transcompilers/unilang/constraint_exporter:if_chain_constraint_exporter",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
])