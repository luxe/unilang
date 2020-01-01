package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "inheritance_item",deps=[
"//code/transcompilers/unilang/structure/model/sections:structure_enums",
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "inheritance_section",deps=[
"inheritance_item"
])