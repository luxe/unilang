package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "meta_author_printer",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings/author:meta_author_tag_options",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "meta_blank_line_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
    ],
)

hcp(
    name = "meta_classification_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "meta_company_name_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "meta_contract_number_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "meta_contract_statement_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "meta_copyright_getter",
    deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/time/calendar/tm_wrappers:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "meta_copyright_statement_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "meta_distribution_statement_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_distribution_statement_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)

hcp(
    name = "meta_external_links_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "meta_file_statement_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "meta_group_names_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)

hcp(
    name = "meta_organizations_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl/sections:meta_company_name_getter",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_organization_options",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)

hcp(
    name = "meta_project_name_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "meta_task_order_getter",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
