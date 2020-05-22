package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "enum_utility_value_printer",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
        "//code/tools/transcompilers/unilang/structure/print:data_member_printer",
        "//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
