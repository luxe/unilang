package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "date_exporter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
"//code/tools/transcompilers/unilang/options/language-specific/html_table:html_table_options",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/tools/transcompilers/unilang/structure/print:struct_derivers",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/program/call:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/contributor:contributor",
"//code/tools/transcompilers/unilang/options/manipulation:case_adjustment_settings",
"//code/tools/transcompilers/unilang/structure/adjust:casing_adjuster",
"//code/utilities/types/vectors/observers:lib",
"//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
"//code/tools/transcompilers/unilang/options/language-specific/processing:processing_options",
"//code/utilities/filesystem/files/observers/lstat_wrap:lib",
"//code/utilities/time/calendar/tm_wrappers:lib"
])