package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "enum_argument_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/tools/transcompilers/unilang/enum_printer/core:enum_value_creator",
"//code/tools/transcompilers/unilang/comment_creator:comment_creator",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/converters:lib",
])

hcp(name = "enum_boilerplate_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/tools/transcompilers/unilang/enum_printer/core:enum_value_creator",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name = "enum_value_creator", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
"//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/converters:lib",
])

hcp(name = "enum_without_utility_values_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/tools/transcompilers/unilang/enum_printer/core:enum_value_creator",
"enum_argument_printer",
"enum_boilerplate_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/vectors/observers:lib",
])

hcp(name = "enum_with_utility_values_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
"//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"enum_argument_printer",
"enum_boilerplate_printer",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/vectors/observers:lib",
])
