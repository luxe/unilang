package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "macro_item",deps=[
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/sections:structure_enums"
])

hcp(name = "macro_section",deps=[
"macro_item"
])