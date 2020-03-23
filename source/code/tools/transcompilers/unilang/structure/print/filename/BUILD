package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "file_name_creator", deps = [
"//code/tools/transcompilers/unilang/options/filesystem:general_filesystem_naming",
"//code/utilities/linguistics/computer:source_language",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/linguistics/computer/file_extension:file_extension_getter",
])

hcp(name = "file_name_getter", deps = [
"//code/tools/transcompilers/unilang/structure/print/export_file_settings:export_file_settings",
"//code/tools/transcompilers/unilang/options/filesystem:general_filesystem_naming",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/tools/transcompilers/unilang/structure/print/filename:file_name_creator",
])