package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:bootstrap_hcp.bzl", "bootstrap_hcp")

bootstrap_hcp(
    name = "hcp_outputs",
)

bootstrap_hcp(
    name = "hcp_outputs_getter",
    deps = [
        "//code/programs/transcompilers/hcp-compiler/official:include_file_printer",
        "//code/programs/transcompilers/hcp-compiler/official/outputs:hcp_outputs",
        "//code/programs/transcompilers/hcp-compiler/official/settings:hcp_settings",
        "//code/programs/transcompilers/hcp-compiler/official/structure:class_structure",
        "//code/programs/transcompilers/shared:json_gen",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/wstrings/transformers/other:lib",
        "//code/utilities/types/wstrings/transformers/trimming:lib",
    ],
)
