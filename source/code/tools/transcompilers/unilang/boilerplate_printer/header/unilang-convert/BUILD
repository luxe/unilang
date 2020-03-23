package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "header_adjuster", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/import:import_section",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/program/common_actions/exits:lib",
])

hcp(name = "header_extension_deriver", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/import:import_section",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/utilities/types/strings/observers/path:lib",
"//code/utilities/linguistics/computer/file_extension:file_extension_getter",
"//code/utilities/linguistics/computer:source_language",
])