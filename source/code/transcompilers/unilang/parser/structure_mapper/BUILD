package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "stamp_expander", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/parser/structure_mapper/important:sub_structure_builder",
"//code/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/transcompilers/unilang/parser/structure_mapper/util:parser_token_stripper",
"//code/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
"//code/transcompilers/unilang/parser/structure_mapper/util:special_parser_filters",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/transformers/search_replace:lib",
"//code/transcompilers/unilang/options/parser:parser_settings",
"//code/utilities/types/vectors/observers:lib",
])

hcp(name = "code_object_creator", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/parser/structure_mapper/important:sub_structure_builder",
"//code/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/transcompilers/unilang/parser/structure_mapper/util:parser_token_stripper",
"//code/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
"//code/transcompilers/unilang/parser/structure_mapper/util:special_parser_filters",
"//code/transcompilers/unilang/parser/structure_mapper:stamp_expander",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/transcompilers/unilang/structure/model:inlined_structures",
"//code/transcompilers/unilang/options/parser:parser_settings",
])