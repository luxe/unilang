package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "stamp_expander", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/parser:parser_token",
"//code/tools/transcompilers/unilang/parser:token_value",
"//code/tools/transcompilers/unilang/parser/structure_mapper/important:sub_structure_builder",
"//code/tools/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_token_stripper",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:special_parser_filters",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/transformers/search_replace:lib",
"//code/tools/transcompilers/unilang/options/parser:parser_settings",
"//code/utilities/types/vectors/observers:lib",
])

hcp(name = "code_object_creator", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/parser:parser_token",
"//code/tools/transcompilers/unilang/parser:token_value",
"//code/tools/transcompilers/unilang/parser/structure_mapper/important:sub_structure_builder",
"//code/tools/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_token_stripper",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:special_parser_filters",
"//code/tools/transcompilers/unilang/parser/structure_mapper:stamp_expander",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
"//code/tools/transcompilers/unilang/options/parser:parser_settings",
"//code/tools/transcompilers/unilang/tokens:get_tokens",
])