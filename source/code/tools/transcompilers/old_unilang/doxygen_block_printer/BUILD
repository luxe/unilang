package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "doxygen_block_maker",
    deps = [
        "doxygen_data",
        "//code/tools/transcompilers/old_unilang/options/comment/doxygen:doxygen_block_options",
        "//code/utilities/types/strings/creators:lib",
        "//code/utilities/types/strings/observers/front_back:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)

hcp(
    name = "doxygen_data_getter_for_data_members",
    deps = [
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:doxygen_block_maker",
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:doxygen_data",
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:doxygen_data_shared",
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:value_constraint_comment_deriver",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method:method_item",
        "//code/tools/transcompilers/old_unilang/structure/print/derivers:identifier_name_deriver",
        "//code/utilities/linguistics/computer/literals/adjuster:literal_adjuster",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
    ],
)

hcp(
    name = "doxygen_data_getter",
    deps = [
        "doxygen_data_getter_for_data_members",
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:doxygen_block_maker",
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:doxygen_data",
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:doxygen_data_shared",
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:value_constraint_comment_deriver",
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer/method_getter:doxygen_data_getter_for_methods",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method:method_item",
        "//code/utilities/linguistics/computer/literals/adjuster:literal_adjuster",
    ],
)

hcp(
    name = "doxygen_data",
    deps = [
    ],
)

hcp(
    name = "doxygen_data_shared",
    deps = [
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:doxygen_data",
        "//code/tools/transcompilers/old_unilang/doxygen_block_printer:grammar_adjuster",
        "//code/tools/transcompilers/old_unilang/options/comment:comment_grammar_settings",
    ],
)

hcp(
    name = "value_constraint_comment_deriver",
    deps = [
        "//code/tools/transcompilers/old_unilang/constraint_exporter:value_constraints_to_interval_constraints",
        "//code/tools/transcompilers/old_unilang/constraint_exporter/interval_constraint",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/data_member:value_constraints",
        "//code/tools/transcompilers/old_unilang/type_converters/type_to_hungarian/qualifier_stripper:type_qualifier_stripper",
        "//code/utilities/linguistics/computer/literals/adjuster:literal_adjuster",
        "//code/utilities/linguistics/computer/types/generic:unilang_type_to_language_type_converter",
        "//code/utilities/types/converters:lib",
    ],
)
