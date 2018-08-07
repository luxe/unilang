package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cpp_object(name = "code_type")

hcp(name = "foreseeable_change", deps=[
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "meta_subgroup", deps=[
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "specification_file", deps=[
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "meta_section", deps=[
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/sections/meta:code_type",
"meta_subgroup",
"specification_file",
"foreseeable_change",
])