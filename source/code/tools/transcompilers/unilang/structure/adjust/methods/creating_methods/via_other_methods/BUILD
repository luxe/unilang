package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "method_utility_function_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_other_methods:method_utility_function_options",
        "//code/tools/transcompilers/unilang/options/sections/data_member:data_member_options",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
        "//code/tools/transcompilers/unilang/structure/print:function_declaration_location",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)
