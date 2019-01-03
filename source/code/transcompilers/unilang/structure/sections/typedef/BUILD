package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "typedef_argument", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "typedef_section", deps = [
"typedef_item"
])

hcp(name = "typedef_item", deps = [
"typedef_argument",
"typedef_result",
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/sections:structure_enums",
])

hcp(name = "typedef_result", deps = [
"//code/transcompilers/unilang/parser:token_value"
])