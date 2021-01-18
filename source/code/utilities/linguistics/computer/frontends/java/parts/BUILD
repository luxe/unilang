package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "boilerplate_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/structure/print/export_file_settings",
        "//code/tools/transcompilers/old_unilang/structure/print/filename:file_name_getter",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/linguistics/computer/frontends/parts/meta:boilerplate_printer",
        "//code/utilities/linguistics/computer/frontends/parts/meta/impl:meta_block_printer",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "package_name_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/structure/print/export_file_settings",
        "//code/tools/transcompilers/old_unilang/structure/print/filename:file_name_getter",
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "imports_getter",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "class_getter",
    deps = [
        "//code/utilities/code:concept_static_tree_structs",
        "//code/utilities/code/query:virtual_method_checker",
        "//code/utilities/comments/doxygen/maker:doxygen_block_printer",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/frontends/java/settings:java_settings",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
