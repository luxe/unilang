package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "parser_aliases", deps = [
"//code/tools/transcompilers/unilang/tokens:token_name",
"//code/tools/transcompilers/unilang/parser:token_value"
])

hcp(name = "special_parser_filters", deps = [
"//code/tools/transcompilers/unilang/parser:parser_token",
"//code/tools/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/tokens:token_group",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
"//code/utilities/types/vectors/observers:lib",
"//code/tools/transcompilers/unilang/tokens:get_tokens",
"//code/tools/transcompilers/unilang/options/parser:parser_settings"
])

hcp(name = "parser_utilities", deps = [
"//code/tools/transcompilers/unilang/parser:token_value",
"//code/tools/transcompilers/unilang/parser:parser_token",
"//code/tools/transcompilers/unilang/tokens:token_name",
"//code/tools/transcompilers/unilang/tokens:token_group",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/sets:lib",
])

hcp(name = "parser_token_stripper", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/import:import_item",
"//code/tools/transcompilers/unilang/structure/model/sections/namespace:namespace_item",
"//code/tools/transcompilers/unilang/structure/model/sections/macro:macro_item",
"//code/tools/transcompilers/unilang/structure/model/sections/inheritance:inheritance_item",
"//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
"//code/tools/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/tools/transcompilers/unilang/parser/structure_mapper/util:special_parser_filters",
"//code/tools/transcompilers/unilang/options/parser:parser_settings",
])