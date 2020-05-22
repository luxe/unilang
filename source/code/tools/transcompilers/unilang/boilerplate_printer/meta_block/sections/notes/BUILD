package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "meta_notes_getter",
    deps = [
        "meta_note_creator",
        "//code/tools/transcompilers/unilang/options/sections/meta:meta_options",
        "//code/tools/transcompilers/unilang/structure/model/sections/meta:meta_section",
        "//code/tools/transcompilers/unilang/structure/print/export_file_settings",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)

hcp(
    name = "meta_note_creator",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/meta:meta_generic_note_options",
        "//code/tools/transcompilers/unilang/structure/print/export_file_settings",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)
