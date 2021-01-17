package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "units_description_adder",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts:portion_options",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/types/converters:lib",
        "//code/utilities/units:unit_suffix_lookuper",
    ],
)

hcp(
    name = "return_results_description_adder",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/comments/doxygen/maker/method_getter/adders:units_description_adder",
        "//code/utilities/types/converters:lib",
    ],
)

hcp(
    name = "suggested_return_identifier_adder",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/comments/doxygen/maker/method_getter/adders:units_description_adder",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method:method_item",
        "//code/tools/transcompilers/old_unilang/structure/print/derivers:identifier_name_deriver",
        "//code/utilities/types/converters:lib",
    ],
)

hcp(
    name = "main_description_adder",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/comments/doxygen/maker:value_constraint_comment_deriver",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method:method_item",
        "//code/tools/transcompilers/old_unilang/structure/print/derivers:identifier_name_deriver",
        "//code/utilities/linguistics/computer/literals/adjuster:literal_adjuster",
        "//code/utilities/types/converters:lib",
        "//code/utilities/units:unit_suffix_lookuper",
    ],
)

hcp(
    name = "contract_description_adder",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "argument_description_adder",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/comments/doxygen/maker/method_getter/adders:units_description_adder",
        "//code/utilities/comments/doxygen/settings:doxygen_parameter_direction",
        "//code/utilities/code/query:argument_direction_decider",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
        "//code/utilities/units:unit_suffix_lookuper",
        "//code/utilities/linguistics/computer/frontends/parts/identifier:function_argument_to_identifier",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "overload_note_adder",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method:method_item",
        "//code/tools/transcompilers/old_unilang/structure/query:is_overload_decider",
    ],
)
