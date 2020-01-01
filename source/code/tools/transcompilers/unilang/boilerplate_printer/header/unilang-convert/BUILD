package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "header_adjuster", deps = [
"//code/transcompilers/unilang/structure/model/sections/import:import_section",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/exits:lib",
])

hcp(name = "header_extension_deriver", deps = [
"//code/transcompilers/unilang/structure/model/sections/import:import_section",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/observers/path:lib",
"//code/transcompilers/unilang/file_extension_getter:file_extension_getter",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])