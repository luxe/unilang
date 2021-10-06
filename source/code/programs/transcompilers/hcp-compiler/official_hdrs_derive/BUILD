package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:bootstrap_hcp.bzl", "bootstrap_hcp")

bootstrap_hcp(
    name = "task_executer",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official:file_name_checker",
        "//code/programs/transcompilers/hcp-compiler/official:hcp_compiler",
        "//code/programs/transcompilers/hcp-compiler/official:hcp_parser",
        "//code/programs/transcompilers/hcp-compiler/official/settings:hcp_settings",
        "//code/programs/transcompilers/hcp-compiler/official_hdrs_derive:header_enricher",
        "//code/programs/transcompilers/hcp-compiler/official_hdrs_derive/program_options:lib",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/wstrings/transformers/other:lib",
    ],
)

bootstrap_hcp(
    name = "header_enricher",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official/settings:hcp_settings",
        "//code/programs/transcompilers/hcp-compiler/official/structure:class_structure",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/wstrings/transformers/other:lib",
    ],
)

cc_binary(
    name = "hcp-compiler",
    srcs = ["main.cpp"],
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official_hdrs_derive:task_executer",
        "//code/programs/transcompilers/hcp-compiler/official_hdrs_derive/program_options:lib",
        "//code/utilities/program/common_actions/backtrace",
        "//code/utilities/program/common_actions/backtrace:exceptions",
        "//code/utilities/program/common_actions/locale:lib",
        "//code/utilities/program/common_actions/signals:all_signal_setter",
    ],
)
