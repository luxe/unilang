package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "forward_declare_printer", deps = [
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/converters:lib",
"//code/tools/transcompilers/unilang/structure/model/sections/forward_declare:forward_declare_item",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/tools/transcompilers/unilang/structure/print/derivers:struct_name_deriver",
])