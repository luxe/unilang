package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "namespace_item", deps = [
"//code/transcompilers/unilang/parser:token_value"
])
hcp(name = "namespace_section", deps = [
"namespace_item"
])