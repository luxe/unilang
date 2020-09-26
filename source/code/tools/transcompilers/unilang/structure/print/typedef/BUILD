package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "typedef_printer",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model/sections/typedef:typedef_item",
        "//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
        "//code/tools/transcompilers/unilang/structure/print/derivers:type_name_deriver",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
