package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "html_table_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/transcompilers/unilang/options/language-specific:html_table_options",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/transcompilers/unilang/structure-printer:struct_derivers",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/shell:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/options/manipulation:case_adjustment_settings",
"//code/transcompilers/unilang/structure-adjuster:casing_adjuster",
"//code/utilities/types/vectors/observers:lib",
"//code/transcompilers/unilang/compiler-frontends/xml:xml_exporter",
"//code/transcompilers/unilang/structure-adjuster:structure_adjuster",
"//code/utilities/types/vectors/operators:lib",
])

hcp(name = "html_table_options_getter", deps = [
"//code/transcompilers/unilang/options/language-specific:html_table_options",
])