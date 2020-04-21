package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object("gender")
cpp_object("species")
hcp(name = "contributor_appearance", deps = [
"//code/tools/transcompilers/unilang/contributor/appearance:species",
"//code/tools/transcompilers/unilang/contributor/appearance:gender"
])