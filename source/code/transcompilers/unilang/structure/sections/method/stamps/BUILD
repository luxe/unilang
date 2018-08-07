package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "method_stamp", deps = [
"//code/transcompilers/unilang/parser:token_value",
"method_stamp_value"
])

hcp(name = "method_stamp_value", deps = [
"//code/transcompilers/unilang/parser:token_value"
])