package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "meta_blank_line_options")

hcp(name = "meta_classification_options")

hcp(name = "meta_contract_number_options")

hcp(name = "meta_distribution_statement_options")

hcp(
    name = "meta_external_link_options",
    deps = ["//code/utilities/linguistics/computer/frontends/parts/meta/settings/other:meta_tag_existence_option"],
)

hcp(name = "meta_file_tag_options")

hcp(name = "meta_generic_note_options")

hcp(name = "meta_organization_options")

hcp(name = "meta_project_name_options")

hcp(name = "meta_watermark_settings")

cpp_object(name = "meta_section_name")

hcp(name = "meta_task_order_options")

hcp(
    name = "meta_options",
    deps = [
        "//code/utilities/comments/code/settings:comment_settings",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_blank_line_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_classification_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_contract_number_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_distribution_statement_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_external_link_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_file_tag_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_generic_note_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_organization_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_project_name_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_section_name",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_task_order_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_watermark_settings",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings/author:meta_author_tag_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings/copyright:meta_copyright_tag_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings/organizations:organization",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings/other:meta_brief_tag_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings/other:meta_bug_tag_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings/other:meta_details_tag_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings/other:meta_group_name_tag_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings/other:meta_warning_tag_options",
    ],
)
