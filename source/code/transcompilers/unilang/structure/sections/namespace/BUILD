package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "namespace_item", deps = [
"//code/transcompilers/unilang/parser:token_value"
])
hcp(name = "namespace_section", deps = [
"namespace_item"
])