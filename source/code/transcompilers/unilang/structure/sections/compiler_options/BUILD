package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "compile_options", deps = [
"//code/transcompilers/unilang/structure/sections/compiler_options:compile_option"
])

hcp(name = "compile_option", deps = [
"//code/transcompilers/unilang/parser:token_value"
])