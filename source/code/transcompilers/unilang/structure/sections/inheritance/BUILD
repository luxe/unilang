package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "inheritance_item",deps=[
"//code/transcompilers/unilang/structure/sections:structure_enums",
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "inheritance_section",deps=[
"inheritance_item"
])