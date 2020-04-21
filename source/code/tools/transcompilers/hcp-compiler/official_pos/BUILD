package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:bootstrap.bzl", "bootstrap_hcp")

bootstrap_hcp(
    name = "task_executer",
    deps = ["//code/tools/transcompilers/hcp-compiler/official/program_options:lib",
    "//code/utilities/program/common_actions/exits:lib",
    "//code/utilities/types/strings/observers/path:lib",
    "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
    "//code/utilities/types/wstrings/transformers/other:lib",
    "//code/utilities/types/converters:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/tools/transcompilers/hcp-compiler/official:file_name_checker",
    "//code/tools/transcompilers/hcp-compiler/official:bazel_deps_printer",
    "//code/tools/transcompilers/hcp-compiler/official:hcp_parser",
    "//code/tools/transcompilers/hcp-compiler/official:hcp_compiler",
    "//code/tools/transcompilers/hcp-compiler/official_pos:position_enricher",
    ]
)

bootstrap_hcp(
    name = "position_enricher",
    deps = [
        "//code/tools/transcompilers/hcp-compiler/official:class_structure",
    ]
)

cc_binary(
    name = "hcp-compiler",
    srcs = ["main.cpp"],
    deps = ["//code/tools/transcompilers/hcp-compiler/official/program_options:lib",
            "//code/utilities/program/common_actions/locale:lib",
            "//code/tools/transcompilers/hcp-compiler/official_pos:task_executer"],
)