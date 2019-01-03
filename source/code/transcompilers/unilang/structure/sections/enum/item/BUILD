package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "enum_subgroup", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "enum_item", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/sections/enum/item/arg:enum_arg",
"//code/transcompilers/unilang/structure/sections:structure_enums",
"enum_subgroup"
])