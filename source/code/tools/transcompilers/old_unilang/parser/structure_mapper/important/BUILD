package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "parser_bindings",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/old_unilang/options/parser/symbols:token_attribute_settings",
        "//code/tools/transcompilers/old_unilang/parser:parser_token",
        "//code/tools/transcompilers/old_unilang/parser/body_parser:body_token_parser",
        "//code/tools/transcompilers/old_unilang/parser/structure_mapper/util:parser_aliases",
        "//code/tools/transcompilers/old_unilang/parser/structure_mapper/util:parser_utilities",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
    ],
)

hcp(
    name = "sub_structure_builder",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/old_unilang/options/parser/symbols:token_attribute_settings",
        "//code/tools/transcompilers/old_unilang/parser:parser_token",
        "//code/tools/transcompilers/old_unilang/parser/body_parser:body_token_parser",
        "//code/tools/transcompilers/old_unilang/parser/entire_body_parser",
        "//code/tools/transcompilers/old_unilang/parser/structure_mapper/important:parser_bindings",
        "//code/tools/transcompilers/old_unilang/parser/structure_mapper/util:parser_aliases",
        "//code/tools/transcompilers/old_unilang/parser/structure_mapper/util:parser_token_stripper",
        "//code/tools/transcompilers/old_unilang/parser/structure_mapper/util:parser_utilities",
        "//code/tools/transcompilers/old_unilang/parser/structure_mapper/util:special_parser_filters",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/utilities/types/general:lib",
    ],
)
