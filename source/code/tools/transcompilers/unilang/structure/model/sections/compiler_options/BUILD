package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "compile_options", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/compiler_options:compile_option"
])

hcp(name = "compile_option", deps = [
"//code/tools/transcompilers/unilang/parser:token_value"
])