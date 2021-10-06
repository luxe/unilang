package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:bootstrap_hcp.bzl", "bootstrap_hcp")

bootstrap_hcp(
    name = "path_data",
    deps = [
    ],
)

bootstrap_hcp(
    name = "class_structure_data",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official/structure:path_data",
    ],
)

bootstrap_hcp(
    name = "class_structure",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official/structure:class_structure_data",
    ],
)

bootstrap_hcp(
    name = "class_structure_creator",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official:header_validator",
        "//code/programs/transcompilers/hcp-compiler/official/settings:hcp_settings",
        "//code/programs/transcompilers/hcp-compiler/official/structure:class_structure",
        "//code/programs/transcompilers/hcp-compiler/official/structure_state:lib",
        "//code/programs/transcompilers/hcp-compiler/official/unicode_parser_symbols:lib",
        "//code/utilities/language_basic/multiple_relational_comparing:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
    ],
)
