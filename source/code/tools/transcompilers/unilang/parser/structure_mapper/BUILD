package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "stamp_expander",
    deps = [
        "//code/tools/transcompilers/unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
        "//code/tools/transcompilers/unilang/parser:parser_token",
        "//code/tools/transcompilers/unilang/parser:token_value",
        "//code/tools/transcompilers/unilang/parser/structure_mapper/important:sub_structure_builder",
        "//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_token_stripper",
        "//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
        "//code/tools/transcompilers/unilang/parser/structure_mapper/util:special_parser_filters",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "code_object_creator",
    deps = [
        "//code/tools/transcompilers/unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
        "//code/tools/transcompilers/unilang/parser:parser_token",
        "//code/tools/transcompilers/unilang/parser:token_value",
        "//code/tools/transcompilers/unilang/parser/structure_mapper:stamp_expander",
        "//code/tools/transcompilers/unilang/parser/structure_mapper/important:sub_structure_builder",
        "//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_token_stripper",
        "//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
        "//code/tools/transcompilers/unilang/parser/structure_mapper/util:special_parser_filters",
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/tokens:get_tokens",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
    ],
)
