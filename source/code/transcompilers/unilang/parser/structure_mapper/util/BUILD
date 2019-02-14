package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "parser_aliases", deps = [
"//code/transcompilers/unilang/tokens:token_name",
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "special_parser_filters", deps = [
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/tokens:token_group",
"//code/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
"//code/utilities/types/vectors/observers:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
"//code/transcompilers/unilang/options/parser:parser_settings"
])

hcp(name = "parser_utilities", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/tokens:token_name",
"//code/transcompilers/unilang/tokens:token_group",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/sets:lib",
])

hcp(name = "parser_token_stripper", deps = [
"//code/transcompilers/unilang/structure/model/sections/import:import_item",
"//code/transcompilers/unilang/structure/model/sections/namespace:namespace_item",
"//code/transcompilers/unilang/structure/model/sections/macro:macro_item",
"//code/transcompilers/unilang/structure/model/sections/inheritance:inheritance_item",
"//code/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/parser/structure_mapper/util:parser_utilities",
"//code/transcompilers/unilang/options/parser/symbols:token_attribute_settings",
"//code/transcompilers/unilang/parser/structure_mapper/util:special_parser_filters",
"//code/transcompilers/unilang/options/parser:parser_settings",
])