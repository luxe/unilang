package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "plant_uml_exporter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/contributor:contributor",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
"//code/tools/transcompilers/unilang/options/language-specific/plant_uml_settings:plant_uml_settings",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/tools/transcompilers/unilang/structure/print:struct_derivers",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/tools/transcompilers/unilang/compiler-frontends/plant_uml_exporter:composition_relationship",
"//code/utilities/shell:lib",
"//code/utilities/filesystem/paths:lib",
"//code/tools/transcompilers/unilang/options/manipulation:case_adjustment_settings",
"//code/tools/transcompilers/unilang/structure/adjust:casing_adjuster",
"//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
"//code/utilities/filesystem/files/observers/lstat_wrap:lib"
])


hcp(name = "composition_relationship")

hcp(name = "plant_uml_options_getter", deps = [
"//code/utilities/filesystem/paths:lib",
"//code/utilities/system:lib",
"//code/tools/transcompilers/unilang/options/language-specific/plant_uml_settings:plant_uml_settings",
])