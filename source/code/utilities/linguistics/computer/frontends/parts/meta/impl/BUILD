package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "meta_block_printer",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/resolve:module_description_resolver",
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/licenses:apache_2_getter",
        "//code/utilities/linguistics/computer/export_file_settings",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_author_printer",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_blank_line_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_classification_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_company_name_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_contract_number_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_contract_statement_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_copyright_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_copyright_statement_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_distribution_statement_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_external_links_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_file_statement_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_group_names_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_organizations_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_project_name_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_task_order_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections/notes:meta_note_creator",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections/notes:meta_notes_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_watermark_settings",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/strings/transformers/watermark:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
