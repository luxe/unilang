package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "code_type")

hcp(name = "foreseeable_change", deps=[
"//code/tools/transcompilers/unilang/parser:token_value"
])

hcp(name = "meta_subgroup", deps=[
"//code/tools/transcompilers/unilang/parser:token_value"
])

hcp(name = "specification_file", deps=[
"//code/tools/transcompilers/unilang/parser:token_value"
])

hcp(name = "meta_section", deps=[
"//code/tools/transcompilers/unilang/parser:token_value",
"//code/tools/transcompilers/unilang/structure/model/sections/meta:code_type",
"meta_subgroup",
"specification_file",
"foreseeable_change",
])