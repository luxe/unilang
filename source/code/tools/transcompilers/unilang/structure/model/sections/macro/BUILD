package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "macro_item",deps=[
"//code/tools/transcompilers/unilang/parser:token_value",
"//code/tools/transcompilers/unilang/structure/model/sections:structure_enums"
])

hcp(name = "macro_section",deps=[
"macro_item"
])