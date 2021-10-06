package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "doxygen_data_getter_for_methods",
    interface_deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/comments/doxygen/maker/method_getter/adders:argument_description_adder",
        "//code/utilities/comments/doxygen/maker/method_getter/adders:contract_description_adder",
        "//code/utilities/comments/doxygen/maker/method_getter/adders:main_description_adder",
        "//code/utilities/comments/doxygen/maker/method_getter/adders:overload_note_adder",
        "//code/utilities/comments/doxygen/maker/method_getter/adders:return_results_description_adder",
        "//code/utilities/comments/doxygen/maker/method_getter/adders:suggested_return_identifier_adder",
        "//code/utilities/linguistics/computer/frontends/parts:module_settings",
    ],
)
