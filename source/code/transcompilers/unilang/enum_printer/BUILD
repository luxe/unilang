package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "enum_section_printer", deps = [
"//code/transcompilers/unilang/structure/sections/enum/item:enum_item",
"//code/transcompilers/unilang/options/sections/enum:enum_options",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:doxygen_block_printer",
"//code/transcompilers/unilang/enum_printer/core:enum_without_utility_values_printer",
"//code/transcompilers/unilang/enum_printer/core:enum_with_utility_values_printer",
"//code/transcompilers/unilang/enum_printer/extra/data:enum_utility_value_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/converters:lib",
])