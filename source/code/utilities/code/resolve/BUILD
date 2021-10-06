package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "module_description_resolver",
    interface_deps = [
        "//code/utilities/code:concept_static_tree_pk_resolver",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/query:class_name_getter",
        "//code/utilities/code/resolve:description_resolve_utilities",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/reflow:sentence_reflower",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp_hdrs_derive(
    name = "data_member_description_resolver",
    interface_deps = [
        "//code/utilities/code:concept_static_tree_pk_resolver",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/query:class_name_getter",
        "//code/utilities/code/resolve:description_resolve_utilities",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/reflow:sentence_reflower",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp_hdrs_derive(
    name = "method_description_resolver",
    interface_deps = [
        "//code/utilities/code:concept_static_tree_pk_resolver",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/query:class_name_getter",
        "//code/utilities/code/resolve:description_resolve_utilities",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/reflow:sentence_reflower",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp_hdrs_derive(
    name = "description_resolve_utilities",
    interface_deps = [
        "//code/utilities/code:concept_static_tree_pk_resolver",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/query:class_name_getter",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/reflow:sentence_reflower",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
