package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "compile_options", deps = [
"//code/transcompilers/unilang/structure/sections/compiler_options:compile_option"
])

hcp(name = "compile_option", deps = [
"//code/transcompilers/unilang/parser:token_value"
])