package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "header_adjuster",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model/sections/import:import_section",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
    ],
)

hcp(
    name = "header_extension_deriver",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model/sections/import:import_section",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/file_extension:file_extension_getter",
        "//code/utilities/types/strings/observers/path:lib",
    ],
)
