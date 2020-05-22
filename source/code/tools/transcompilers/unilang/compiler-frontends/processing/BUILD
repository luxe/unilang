package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "processing_exporter",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/html_table:html_table_options",
        "//code/tools/transcompilers/unilang/options/language-specific/processing:processing_options",
        "//code/tools/transcompilers/unilang/options/manipulation:case_adjustment_settings",
        "//code/tools/transcompilers/unilang/structure/adjust:casing_adjuster",
        "//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/structure/print:struct_derivers",
        "//code/utilities/contributor",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "processing_options_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/processing:processing_options",
        "//code/utilities/personal/life:company_getter",
    ],
)
