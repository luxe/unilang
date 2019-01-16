package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "type_item", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "type_section", deps = [
"type_item"
])