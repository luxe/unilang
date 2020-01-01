package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "parser_bindings", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/parser:parser_token",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_aliases",
"//code/tools/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
"//code/tools/transcompilers/unilang/parser/body_parser:body_token_parser",
"//code/tools/transcompilers/unilang/options/parser:parser_settings",
])

hcp(name = "sub_structure_builder", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/parser:parser_token",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_aliases",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
"//code/tools/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/tools/transcompilers/unilang/parser/structure_mapper/important:parser_bindings",
"//code/tools/transcompilers/unilang/parser/body_parser:body_token_parser",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_token_stripper",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:special_parser_filters",
"//code/tools/transcompilers/unilang/parser/entire_body_parser:entire_body_parser",
"//code/utilities/types/general:lib",
"//code/tools/transcompilers/unilang/options/parser:parser_settings",
])