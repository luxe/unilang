package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "pluralization_pair")
hcp(name = "irregular_inflections", deps = [
"pluralization_pair"
])