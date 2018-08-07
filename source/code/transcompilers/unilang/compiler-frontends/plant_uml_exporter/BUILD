package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "plant_uml_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/structure:inlined_structures",
"//code/transcompilers/unilang/options/language-specific/plant_uml_settings:plant_uml_settings",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/transcompilers/unilang/structure-printer:struct_derivers",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/compiler-frontends/plant_uml_exporter:composition_relationship",
"//code/utilities/shell:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/options/manipulation:case_adjustment_settings",
"//code/transcompilers/unilang/structure-adjuster:casing_adjuster",
"//code/transcompilers/unilang/structure-adjuster:structure_adjuster",
])


hcp(name = "composition_relationship")

hcp(name = "plant_uml_options_getter", deps = [
"//code/utilities/filesystem/paths:lib",
"//code/utilities/system:lib",
"//code/transcompilers/unilang/options/language-specific/plant_uml_settings:plant_uml_settings",
])