package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "enum_arg", deps = [
"//code/transcompilers/unilang/parser:token_value",
"enum_arg_subscribed_subgroup"
])

hcp(name = "enum_arg_subscribed_subgroup", deps = [
"//code/transcompilers/unilang/parser:token_value"
])