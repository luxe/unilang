package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "file_name_creator",
    deps = [
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/file_extension:file_extension_getter",
        "//code/utilities/linguistics/computer/frontends/parts/filesystem:general_filesystem_naming",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
    ],
)

hcp(
    name = "file_name_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/structure/print/export_file_settings",
        "//code/tools/transcompilers/old_unilang/structure/print/filename:file_name_creator",
        "//code/utilities/linguistics/computer/frontends/parts/filesystem:general_filesystem_naming",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
    ],
)
