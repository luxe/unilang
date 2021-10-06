package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "data_main_description_adder",
    interface_deps = [
        "//code/utilities/code:concept_static_tree_pk_resolver",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/resolve:data_member_description_resolver",
        "//code/utilities/comments:sentences_fixer",
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/linguistics/computer/frontends/parts/identifier:data_member_to_identifier",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
