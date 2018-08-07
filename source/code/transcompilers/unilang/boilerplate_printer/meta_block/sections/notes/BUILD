package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "meta_notes_getter", deps = [
"//code/transcompilers/unilang/structure/sections/meta:meta_section",
"//code/transcompilers/unilang/options/sections/meta:meta_options",
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"meta_note_creator",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
])

hcp(name = "meta_note_creator", deps = [
"//code/transcompilers/unilang/options/sections/meta:meta_generic_note_options",
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/appending:lib",
])