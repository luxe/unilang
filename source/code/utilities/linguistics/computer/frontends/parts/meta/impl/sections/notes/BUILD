package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "meta_notes_getter",
    deps = [
        "meta_note_creator",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/tools/transcompilers/old_unilang/structure/print/export_file_settings",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)

hcp(
    name = "meta_note_creator",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_generic_note_options",
        "//code/tools/transcompilers/old_unilang/structure/print/export_file_settings",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)
