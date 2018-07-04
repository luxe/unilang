package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "typedef_printer", deps = [
"//code/transcompilers/unilang/structure/sections/typedef:typedef_item",
"//code/transcompilers/unilang/structure-printer:doxygen_block_printer",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/structure-printer/derivers:type_name_deriver",
"//code/utilities/converters:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/vectors/observers:lib",
])