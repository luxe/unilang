package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "enum_section_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
"//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/tools/transcompilers/unilang/enum_printer/core:enum_without_utility_values_printer",
"//code/tools/transcompilers/unilang/enum_printer/core:enum_with_utility_values_printer",
"//code/tools/transcompilers/unilang/enum_printer/extra/data:enum_utility_value_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/converters:lib",
])