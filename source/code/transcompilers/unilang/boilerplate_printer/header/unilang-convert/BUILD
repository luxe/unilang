package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "header_adjuster", deps = [
"//code/transcompilers/unilang/structure/sections/import:import_section",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/exits:lib",
])

hcp(name = "header_extension_deriver", deps = [
"//code/transcompilers/unilang/structure/sections/import:import_section",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/observers/path:lib",
])