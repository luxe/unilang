package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "parser_bindings", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/parser_tokens_to_structure_converter/util:parser_aliases",
"//code/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/transcompilers/unilang/parser_tokens_to_structure_converter/util:parser_utilities",
"//code/transcompilers/unilang/parser/body_parser:body_token_parser",
])

hcp(name = "sub_structure_builder", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/parser_tokens_to_structure_converter/util:parser_aliases",
"//code/transcompilers/unilang/parser_tokens_to_structure_converter/util:parser_utilities",
"//code/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/transcompilers/unilang/parser_tokens_to_structure_converter/important:parser_bindings",
"//code/transcompilers/unilang/parser/body_parser:body_token_parser",
"//code/transcompilers/unilang/parser_tokens_to_structure_converter/util:parser_token_stripper",
"//code/transcompilers/unilang/parser_tokens_to_structure_converter/util:special_parser_filters",
"//code/transcompilers/unilang/parser/entire_body_parser:entire_body_parser",
"//code/utilities/types/general:lib",
])