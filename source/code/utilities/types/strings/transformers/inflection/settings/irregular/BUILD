package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "pluralization_pair")
hcp(name = "irregular_inflections", deps = [
"pluralization_pair"
])