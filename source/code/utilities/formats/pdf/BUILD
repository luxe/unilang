package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "pdf_settings",
    interface_deps = [
        "//code/utilities/linguistics/computer/frontends/markdown/settings:markdown_settings",
        "//code/utilities/program/wrappers/pandoc/settings:pandoc_pdf_settings",
    ],
)

hcp_hdrs_derive(
    name = "pdf_creator",
    interface_deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/temp:existing_temp_file",
        "//code/utilities/filesystem/files/temp:temp_file",
        "//code/utilities/formats/pdf:csl_template_getter",
        "//code/utilities/formats/pdf:latex_template_getter",
        "//code/utilities/formats/pdf:pdf_settings",
        "//code/utilities/linguistics/computer/frontends/markdown:markdown_str_getter",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/program/wrappers/pandoc:pandoc_pdf_generator",
        "//code/utilities/program/wrappers/pandoc/settings:pandoc_pdf_settings",
        "//code/utilities/types/general:lib",
    ],
)

hcp_hdrs_derive(
    name = "latex_template_getter",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "csl_template_getter",
    interface_deps = [
    ],
)
