package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "forward_declare_printer", deps = [
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/transcompilers/unilang/structure/sections/forward_declare:forward_declare_item",
"//code/transcompilers/unilang/structure-printer:doxygen_block_printer",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/transcompilers/unilang/structure-printer/derivers:struct_name_deriver",
])