package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "doxygen_block_maker",
    deps = [
        "doxygen_data",
        "//code/utilities/comments/doxygen/settings:doxygen_block_options",
        "//code/utilities/types/strings/creators:lib",
        "//code/utilities/types/strings/observers/front_back:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)

hcp(
    name = "doxygen_data_getter",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/comments/doxygen/maker/method_getter:doxygen_data_getter_for_methods",
        "//code/utilities/comments/doxygen/maker/data_getter:doxygen_data_getter_for_data_members",
        "//code/utilities/comments/doxygen/maker/module_getter:doxygen_data_getter_for_modules",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
    ],
)

hcp(
    name = "doxygen_data",
    deps = [
    ],
)

hcp(
    name = "doxygen_data_shared",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/linguistics/grammar:grammar_adjuster",
        "//code/utilities/linguistics/grammar/settings:comment_grammar_settings",
    ],
)

hcp(
    name = "doxygen_block_printer",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/comments/doxygen/maker:doxygen_data_getter",
        "//code/utilities/comments/doxygen/maker:doxygen_data_shared",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)