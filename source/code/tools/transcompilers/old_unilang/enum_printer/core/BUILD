package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "enum_argument_printer",
    deps = [
        "//code/tools/transcompilers/old_unilang/enum_printer/core:enum_value_creator",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/enum/item:enum_item",
        "//code/tools/transcompilers/old_unilang/structure/print:doxygen_block_printer",
        "//code/utilities/comments/code:comment_creator",
        "//code/utilities/linguistics/computer/frontends/parts/enum:enum_options",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)

hcp(
    name = "enum_boilerplate_printer",
    deps = [
        "//code/tools/transcompilers/old_unilang/enum_printer/core:enum_value_creator",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/enum/item:enum_item",
        "//code/tools/transcompilers/old_unilang/structure/print:doxygen_block_printer",
        "//code/utilities/linguistics/computer/frontends/parts/enum:enum_options",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)

hcp(
    name = "enum_value_creator",
    deps = [
        "//code/tools/transcompilers/old_unilang/structure/model/sections/enum/item:enum_item",
        "//code/utilities/linguistics/computer/frontends/parts/enum:enum_options",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/other:lib",
    ],
)

hcp(
    name = "enum_without_utility_values_printer",
    deps = [
        "enum_argument_printer",
        "enum_boilerplate_printer",
        "//code/tools/transcompilers/old_unilang/enum_printer/core:enum_value_creator",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/enum/item:enum_item",
        "//code/tools/transcompilers/old_unilang/structure/print:doxygen_block_printer",
        "//code/utilities/linguistics/computer/frontends/parts/enum:enum_options",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/casing:case_format_style",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "enum_with_utility_values_printer",
    deps = [
        "enum_argument_printer",
        "enum_boilerplate_printer",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/enum/item:enum_item",
        "//code/tools/transcompilers/old_unilang/structure/print:doxygen_block_printer",
        "//code/utilities/linguistics/computer/frontends/parts/enum:enum_options",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)
