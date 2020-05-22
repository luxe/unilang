package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "implicit_global_header_comment_deriver",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model:structure",
    ],
)

hcp(
    name = "header_collector",
    deps = [
        "//code/tools/transcompilers/unilang/boilerplate_printer/header:implicit_global_header_comment_deriver",
        "//code/tools/transcompilers/unilang/boilerplate_printer/header/relationships:import_relationship_comment_deriver",
        "//code/tools/transcompilers/unilang/boilerplate_printer/header/unilang-convert:header_extension_deriver",
        "//code/tools/transcompilers/unilang/comment_creator",
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model/sections/import:import_section",
        "//code/tools/transcompilers/unilang/structure/print/export_file_settings",
        "//code/tools/transcompilers/unilang/structure/print/filename:file_name_getter",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "header_printer",
    deps = [
        "//code/tools/transcompilers/unilang/boilerplate_printer/header:header_collector",
        "//code/tools/transcompilers/unilang/boilerplate_printer/header/block:header_block_comment_getter",
        "//code/tools/transcompilers/unilang/boilerplate_printer/header/unilang-convert:header_adjuster",
        "//code/tools/transcompilers/unilang/comment_creator",
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/options/language-specific/hidl:hidl_export_settings",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model/sections/import:import_section",
        "//code/tools/transcompilers/unilang/structure/print/filename:file_name_getter",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
    ],
)
