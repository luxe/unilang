package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "main_description_adder",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/linguistics/computer/frontends/parts/identifier:data_member_to_identifier",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)